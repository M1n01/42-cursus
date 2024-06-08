#include "../includes/Serializer.hpp"
#include <iostream>

int main()
{
    // Dataオブジェクトの作成
    Data originalData;
    originalData.value = 123; // 値の設定

    // シリアライズ
    uintptr_t serializedData = Serializer::serialize(&originalData);

    // デシリアライズ
    Data *deserializedData = Serializer::deserialize(serializedData);

    // 結果の表示
    std::cout << "Original Data Address: " << &originalData << std::endl;
    std::cout << "Deserialized Data Address: " << deserializedData << std::endl;
    std::cout << "Deserialized Data Value: " << deserializedData->value << std::endl;

    // ポインタが同じかどうかの確認
    if (&originalData == deserializedData)
    {
        std::cout << "Success: Original and deserialized pointers are the same." << std::endl;
    }
    else
    {
        std::cout << "Error: Pointers do not match." << std::endl;
    }

    return 0;
}
