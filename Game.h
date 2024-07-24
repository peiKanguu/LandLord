#pragma once

// 游戏类，管理斗地主游戏的主要逻辑
#include "Deck.h"
#include "Player.h"
#include"CardCounter.h"
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

