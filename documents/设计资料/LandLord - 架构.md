
---
### **架构**
```plaintext
- LandlordGame (项目根目录)
  - src (源代码)
    - service (服务端逻辑)
      - Game.h / Game.cpp (斗地主游戏逻辑)
      - System.h
	      - Login.cpp (登录账号 - 获取信息并进行比对)
	      - Register.cpp (注册账号 - 保存信息到服务器)
      - Player.h / Player.cpp (玩家逻辑 抢地主/不抢 出牌/过)
      - Card.h / Card.cpp (牌的表示)
      - Deck.h / Deck.cpp (牌堆逻辑)
      - CardCounter.h / CardCounter.cpp (记牌器逻辑)
    - view (视图端逻辑)
      - Buttons.h / Buttons.cpp (按钮类)
      - TextBox.h / TextBox.cpp (输入框类)
      - GUI
        - MainGUI.h / MainGUI.cpp (主页面)
        - LoginGUI.h / LoginGUI.cpp (登录界面)
        - RegisterGUI.h / RegisterGUI.cpp (注册界面)
        - LobbyGUI.h / LobbyGUI.cpp (大厅界面)
        - PokerTableGUI.h / PokerTableGUI.cpp (游戏界面/牌桌)
        - SettingsGUI.h / SettingsGUI.cpp (设置界面)
        - AccountGUI.h / AccountGUI.cpp (账号界面)
        - SettlementGUI.h / SettlementGUI.cpp (结算界面)
        - 
    - main.cpp (主程序入口)
  - assets (资源文件)
    - images (图像资源)
    - sounds (声音资源)
```

说明：
1. GUI界面需要绘制按钮，按下按钮后需要实现相应的功能
2. 匹配需要满3人才能开始游戏
3. 输入框是用来输入信息的（例如账号，密码等。不通过终端输入）
4. 一些GUI里的内容是动态的，完成一定操作后需要刷新以显示效果（例如在叫地主的区域同样可以用来选择出牌或不出）
---
### 游戏规则参考：
简介：该游戏由三人玩一副牌，地主为一方，其余两家为另一方，双方对战，先出完手中牌的一方胜。

**游戏规则（一副牌规则）**  

**1** **、发牌**

一副牌 54 张，一人 17 张，留 3 张做底牌，在确定地主之前玩家不能看底牌。

**2** **、叫牌**

叫牌按出牌的顺序轮流进行，每人只能叫一次。叫牌时可以叫 “1 分 ” ， “2 分 ” ， “3 分 ” ， “ 不叫 ” 。后叫牌者只能叫比前面玩家高的分或者不叫。叫牌结束后所叫分值最大的玩家为地主；如果有玩家叫 “3 分 ” 则立即结束叫牌，该玩家为地主；如果都不叫，则重新发牌，重新叫牌。

**3** **、第一个叫牌的玩家**

第一轮叫牌的玩家由系统选定，以后每一轮首先叫牌的玩家按出牌顺序轮流担任。

**4** **、出牌**

将三张底牌交给地主，并亮出底牌让所有人都能看到。地主首先出牌，然后按逆时针顺序依次出牌，轮到用户跟牌时，用户可以选择 “ 不出 ” 或出比上一个玩家大的牌。某一玩家出完牌时结束本局。

**5** **、牌型**

火箭：即双王（大王和小王），最大的牌。  
炸弹：四张同数值牌（如四个 7 ）。  
单牌：单个牌（如红桃 5 ）。  
对牌：数值相同的两张牌（如梅花 4+ 方块 4 ）。  
三张牌：数值相同的三张牌（如三个 J ）。  
三带一：数值相同的三张牌 + 一张单牌或一对牌。例如： 333+6 或 444+99  
单顺：五张或更多的连续单牌（如： 45678 或 78910JQK ）。不包括 2 点和双王。  
双顺：三对或更多的连续对牌（如： 334455 、7788991010JJ ）。不包括 2 点和双王。  
三顺：二个或更多的连续三张牌（如： 333444 、 555666777888 ）。不包括 2 点和双王。  
飞机带翅膀：三顺＋同数量的单牌（或同数量的对牌）。  
如： 444555+79 或 333444555+7799JJ  
四带二：四张牌＋两手牌。（注意：四带二不是炸弹）。  
如： 5555 ＋ 3 ＋ 8 或 4444 ＋ 55 ＋ 77 。

**6** **、牌型的大小**

火箭最大，可以打任意其他的牌。  
炸弹比火箭小，比其他牌大。都是炸弹时按牌的分值比大小。  
除火箭和炸弹外，其他牌必须要牌型相同且总张数相同才能比大小。  
单牌按分值比大小，依次是 大王 > 小王 >2>A>K>Q>J>10>9>8>7>6>5>4>3 ，不分花色。  
对牌、三张牌都按分值比大小。  
顺牌按最大的一张牌的分值来比大小。  
飞机带翅膀和四带二按其中的三顺和四张部分来比，带的牌不影响大小。

**7** **、胜负判定**

任意一家出完牌后结束游戏，若是地主先出完牌则地主胜，否则另外两家胜。

**8** **、积分**

底分：叫牌的分数  
倍数：初始为 1 ，每出一个炸弹或火箭翻一倍。（火箭和炸弹留在手上没出的不算）

一局结束后：  
地主胜：地主得分为 2* 底分 * 倍数。 其余玩家各得： - 底分 * 倍数  
地主败：地主得分为 -2* 底分 * 倍数。 其余玩家各得：底分 * 倍数  
地主所有牌出完，其他两家一张都未出： 分数 * 2  
其他两家中有一家先出完牌，地主只出过一手牌： 分数 * 2

逃跑扣分：底分 * 倍数 *3  
还没人叫牌时逃跑：扣 3 分

---
### **Button 类**
```cpp
#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <functional>
#include <easyx.h>

class Button {
public:
    // 使用颜色背景的构造函数
    Button(int x, int y, int width, int height, const std::string& label, std::function<void()> onClick);

    // 使用图片背景的构造函数
    Button(int x, int y, int width, int height, const std::string& label, const std::string& imagePath, std::function<void()> onClick);

    ~Button();

    void draw() const;
    bool isClicked(int mouseX, int mouseY) const;
    void click() const;

private:
    int x, y; // 按钮的左上角坐标
    int width, height; // 按钮的宽度和高度
    std::string label; // 按钮的标签
    std::function<void()> onClick; // 按钮的点击事件回调函数
    IMAGE* backgroundImage; // 按钮的背景图片
};

#endif // BUTTON_H
```

### **输入框类**
用来输入信息（例如账号，密码）
```cpp
#include <string>
#include <easyx.h>

class TextBox {
public:
    TextBox(int x, int y, int width, int height);
    ~TextBox();

    void draw() const;
    void handleInput();
    std::string getText() const;

private:
    int x, y; // 输入框的左上角坐标
    int width, height; // 输入框的宽度和高度
    std::string text; // 输入框中的文本
    bool isActive; // 输入框是否处于激活状态，激活了才能输入信息
    void drawBorder() const; //绘制边框
};
```
### **主页面 MainGUI.h**
```cpp
class MainGUI {
public:
    MainGUI();
    void show(); // 绘制界面（参考原型图）

private:
    Button loginButton;
    Button registerButton;
    Button exitButton;
    Button devOptionsButton;
};
```

### **注册页面 RegisterGUI.h**
```cpp
class RegisterGUI {
public:
    RegisterGUI();
    void show(); // 绘制界面（参考原型图）

private:
    Button confirmButton;
    Button exitButton;
    Button rentrunButton;
};
```

### **登录页面 LoginGUI.h**
```cpp
class LoginGUI {
public:
    LoginGUI();
    void show(); // 绘制界面（参考原型图）

private:
    Button confirmButton;
    Button exitButton;
    Button rentrunButton;
};
```
### **大厅页面 LobbyGUI.h**
```cpp

class LobbyGUI {
public:
    LobbyGUI();
    void show(); // 绘制界面（参考原型图）

private:
    Button confirmButton;
    Button exitButton;
    Button settingButton;
    Button matchButton;
    Button AIMatchButton; // 人机
    Button accountButton;
    Button rentrunButton;
};
```

### **游戏界面PokerTableGUI.h**
```cpp
class PokerTableGUI {
public:
    PokerTableGUI();
    void show(); // 绘制界面（参考原型图）

private:
    Button ChatButton;
    Button exitButton;
    Button settingButton;
    Button rentrunButton;
};
```
### **设置界面SettingGUI.h**

```cpp
class SettingGUI {
public:
    SettingGUI();
    void show(); // 绘制界面（参考原型图）

private:
    Button volumeButton; // 调节音量按钮
    Button soundButton;  // 交接音效按钮
    Button exitButton;
    Button returnButton;
};
```

### **账号界面AccountGUI.h**

```cpp
class AccountGUI {
public:
    AccountGUI();
    void show(); // 绘制界面（参考原型图）

private:
    Button setNickname; // 修改昵称按钮
    Button setGender; // 修改性别
    Button setBirthday; // 修改生日按钮
    Button exitButton;
    Button returnButton;
};
```

### **结算界面SettlementGUI.h**

```cpp
class SettlementGUI {
public:
    SettlementGUI();
    void show(); // 绘制界面（参考原型图）

private:
    Button continueButton; // 继续游戏按钮
    Button exitButton;     // 退出游戏按钮
    Button returnButton;   // 返回大厅按钮
    Button settingButton;
};
```
### Game.h

```cpp
// 游戏类，管理斗地主游戏的主要逻辑

#include "Deck.h"
#include "Player.h"
#include <vector>

class Game {
public:
    Game();
    void startGame();   // 开始游戏
    void dealCards();   // 发牌
    void bidForLandlord(); // 叫地主
    void determineWinner(); // 判定胜负
    
private:
    Deck deck;
    std::vector<Player> players; // 玩家列表
    std::vector<Card> bottomCards; // 底牌
    int landlordIndex; // 地主的玩家索引
    int currentPlayerIndex; // 当前玩家索引
    int baseScore; // 底分
    int multiplier; // 倍数
    std::vector<Card> lastPlayedCards; // 记录上一次出的牌
    CardCounter cardCounter; // 记牌器
    
    bool isValidPlay(const std::vector<Card>& playedCards, const std::vector<Card>& lastPlayedCards); // 检查出牌是否有效
    void showBottomCards();
    void resetGame();
    
    // 游戏循环
    // 控制游戏的主要流程，直到有玩家获胜
    void gameLoop();
	
	// 玩家出牌 
	// 参数：player（当前玩家） 
	void playerPlay(Player& player);
};

#endif // GAME_H
```

### System/Login.h

```cpp
// 登录类，处理用户登录逻辑
class Login {
public:
    // 验证用户登录
    // 参数：username（用户名），password（密码）
    // 返回值：登录是否成功
    static bool authenticate(const std::string& username, const std::string& password);
};
```

### System/Register.h

```cpp
// 注册类，处理用户注册逻辑
class Register {
public:
    // 注册新用户
    // 参数：username（用户名），password（密码）
    // 返回值：注册是否成功
    static bool addUser(const std::string& username, const std::string& password);
};
```

### Player.h

```cpp
// 玩家类，管理玩家的操作和状态
#include "Card.h"
#include <vector>
#include <string>

class Player {
public:
    Player(const std::string& name);
    void addCard(const Card& card);
    void addCards(const std::vector<Card>& cards);
    int makeBid(int highestBid); // 叫分
    std::vector<Card> playCards(const std::vector<Card>& lastPlayedCards); // 出牌
    bool hasWon() const; // 判断是否获胜
    const std::string& getName() const;
    void resetHand(); // 重置手牌

private:
    std::string name;
    std::vector<Card> hand;
    bool won;

    bool isValidPlay(const std::vector<Card>& playedCards, const std::vector<Card>& lastPlayedCards);
};

#endif // PLAYER_H

```

### Card.h

```cpp
// 卡牌类，表示一张扑克牌
class Card {
public:
    // 构造函数
    // 参数：value（卡牌值），suit（花色）
    Card(int value, const std::string& suit);
    
    // 获取卡牌值
    // 返回值：卡牌值
    int getValue() const;
    
    // 获取卡牌花色
    // 返回值：卡牌花色
    std::string getSuit() const;
    
    // 获取卡牌字符串表示
    // 返回值：卡牌的字符串表示
    std::string toString() const;

private:
    int value; // 卡牌值
    std::string suit; // 卡牌花色
};
```

### Deck.h

```cpp
// 牌堆类，管理一副扑克牌的操作
class Deck {
public:
    // 构造函数
    Deck();
    
    // 洗牌
    void shuffle();
    
    // 发牌
    // 返回值：发出的一张牌
    Card deal();

private:
    std::vector<Card> cards; // 卡牌堆
    int currentCardIndex; // 当前发牌位置
};
```

### CardCounter.h
```cpp
// 记牌器类，用来记录和显示已打出的牌
class CardCounter {
public:
    // 构造函数
    CardCounter();
    
    // 记录一张牌被打出
    // 参数：card（被打出的卡牌）
    void cardPlayed(const Card& card);
    
    // 获取已打出的牌的数量
    // 参数：card（要查询的卡牌）
    // 返回值：该卡牌已打出的数量
    int getCardCount(const Card& card) const;
    
    // 显示所有已打出的牌及其数量
    void display() const;

private:
    std::map<std::string, int> cardCounts; // 记录每张牌被打出的数量

    // 生成卡牌的唯一标识符
    // 参数：card（要生成标识符的卡牌）
    // 返回值：卡牌的唯一标识符
    std::string generateCardKey(const Card& card) const;
};
```

















