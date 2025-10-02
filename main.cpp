#include <iostream>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "third_party/stb/stb_image.h"



void decode_steganography(int image_data[], int data_size, std::string key) {
    
    int currentIndex = 1000;
    int key_char_index = 0;


    while (true) {
        char key_char = key[key_char_index % key.length()];
        currentIndex += static_cast<int>(key_char);
        
        if (currentIndex >= data_size) {
            break; 
        }

        int secret_value = image_data[currentIndex];

        if (secret_value == 0) {
            break;
        }

        std::cout << static_cast<char>(secret_value)
        key_char_index++;
    }
}

// DO NOT EDIT THE MAIN FUNCTION
int main() {
    const char* image_path = "secret.png";
    int width, height, channels;

    unsigned char* img_data_char = stbi_load(image_path, &width, &height, &channels, 1);

    int data_size = width * height;

    int* image_data_int = new int[data_size];
    for (int i = 0; i < data_size; ++i) {
        image_data_int[i] = (int)img_data_char[i];
    }void decode_steganography(int image_data[], int data_size, std::string key) {
    
    // 시작 위치는 1000으로 동일합니다.
    int currentIndex = 1000;
    int key_char_index = 0;

    // 기존 코드와의 가장 큰 차이점은 루프의 순서입니다.
    while (true) {
        // 1. 다음 위치로 먼저 점프합니다.
        char key_char = key[key_char_index % key.length()];
        currentIndex += static_cast<int>(key_char);
        
        // 2. 점프한 후에 배열 범위를 벗어나는지 확인합니다.
        if (currentIndex >= data_size) {
            break; // 범위를 벗어나면 종료
        }

        // 3. 점프한 위치에서 값을 읽어옵니다.
        int secret_value = image_data[currentIndex];

        // 4. 읽어온 값이 0인지 확인하여 종료 조건을 체크합니다.
        if (secret_value == 0) {
            break;
        }

        // 5. 유효한 값이면 문자로 변환하여 출력합니다.
        std::cout << static_cast<char>(secret_value);
        
        // 6. 다음 key를 사용하기 위해 인덱스를 증가시킵니다.
        key_char_index++;
    }
}

    stbi_image_free(img_data_char);

    std::string user_key;
    std::cout << "Of the four pillars of OOP, what is the principle of separating interface and implementation? (First letter capitalized): ";
    std::cin >> user_key;

    std::cout << "------------------------------------------" << std::endl;
    decode_steganography(image_data_int, data_size, user_key);
    std::cout << "\n------------------------------------------" << std::endl;

    delete[] image_data_int;

    return 0;
}
