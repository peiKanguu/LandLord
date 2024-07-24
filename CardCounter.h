#pragma once
#include<map>
#include<string>
#include"Card.h"

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