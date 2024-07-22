#pragma once

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