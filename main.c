#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

const char *WORDS[] = {"word", "beer", "timber", "time", "water", "teacher", "student", "book", "music", "movie", "game", "food", "cloth", "shoe", "hair", "eye", "nose", "ear", "mouth", "hand", "foot", "heart", "mind", "soul", "dream", "hope", "love", "peace", "joy", "sorrow", "anger", "fear", "courage", "wisdom", "knowledge", "ignorance", "truth", "lie", "honesty", "dishonesty", "friend", "enemy", "alcohol", "coffee", "tea", "milk", "bread", "rice", "pasta", "vegetable", "fruit", "meat", "fish", "bird", "animal", "plant", "tree", "flower", "grass", "sand", "stone", "metal", "wood", "glass", "plastic", "paper", "ink", "paint", "color", "black", "white", "red", "green", "blue", "yellow", "orange", "purple", "brown", "pink", "grey", "silver", "gold", "diamond", "ruby", "emerald", "sapphire", "quartz", "pearl", "jewel", "crystal", "rain", "snow", "wind", "fire", "ice", "smoke", "mist", "fog", "cloud", "sun", "moon", "star", "galaxy", "universe"};
const char ALPHABET[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main();

void check(int len, char list[len],char correct_letters[len],char checked_letters[127],int checked_num,int stage,const char rand_word[]) {
    printf("\033[2J\033[H");
    printf("\x1b[1m\x1b[21mHANGMAN\n\n\x1b[0m");

    char input;
    int checks = 0;
    int checked_successfully = 0;

    for(int i = 0;i < len;i++){
        if(correct_letters[i] == list[i]){
            checks += 1;
        };
    };

    for(int i = 0;i < len;i++){
        printf("%c",correct_letters[i]);
    };
    printf("\n");
    
    printf("Checked Letters: \x1b[3m");
    if(checked_letters[0] != '_'){
        for(int i = 0;i < 100;i++){
            if(checked_letters[i] != ' ' && checked_letters[i] != '\n' && checked_letters[i] != '\0' ){
                printf("%c ",checked_letters[i]);
            };
        };
    };
    printf("\x1b[0m");

    if(stage == 0){
        printf("\n\n\n\n\n\n");
    }else if(stage == 1){
        printf("\n\n\n\n\n\n_______");
    }else if(stage == 2){
        printf("\n       \n   |   \n   |   \n   |   \n   |   \n___|___");
    }else if(stage == 3){
        printf("\n   _______\n   |/  \n   |   \n   |   \n   |   \n___|___");
    }else if(stage == 4){
        printf("\n   _______\n   |/    |\n   |     o\n   |   \n   |   \n___|___");
    }else if(stage == 5){
        printf("\n   _______\n   |/    |\n   |     o\n   |     |   \n   |   \n___|___");
    }else if(stage == 6){
        printf("\n   _______\n   |/    |\n   |     o\n   |    /|   \n   |   \n___|___");
    }else if(stage == 7){
        printf("\n   _______\n   |/    |\n   |     o\n   |    /|\\  \n   |   \n___|___");
    }else if(stage == 8){
        printf("\n   _______\n   |/    |\n   |     o\n   |    /|\\  \n   |    / \n___|___");
    }else if(stage == 9){
        printf("\n   _______\n   |/    |\n   |     o\n   |    /|\\  \n   |    / \\\n___|___");
    }

    if(stage >= 9){
        printf("\x1b[31m\nYou have lost! The Word was \x1b[0m%s\x1b[0m\n",rand_word);
        printf("Play again? (y/n)\n>");
        char answer;
        scanf(" %c",&answer);
        if(answer == 'y'){
            main();
        }else{
            exit(0);
        }
    }

    if(checks == len){
        printf("\x1b[32m\nYou have won!\x1b[0m\n");
        printf("Play again? (y/n)\n>");
        char answer;
        scanf(" %c",&answer);
        if(answer == 'y'){
            main();
        }else{
            exit(0);
        }
    };

    printf("\n\x1b[1mEnter a letter: \x1b[0m");
    scanf(" %s", &input);
    if(strlen(&input) > 1){
        check(len,list,correct_letters,checked_letters,checked_num,stage,rand_word);
    };

    int wrong_letters = 0;
    for(int i = 0;i < sizeof(ALPHABET);i++){
        if(input != ALPHABET[i]){
            wrong_letters++;
        }
    }
    if(wrong_letters == 26){
        check(len,list,correct_letters,checked_letters,checked_num,stage,rand_word);
    }

    int ok = 0;
    for(int i = 0;i < sizeof(&checked_letters)/sizeof(checked_letters[0]);i++){
        if(checked_letters[i] != input){
            ok++;
        }else {
            ok = 0;
        };
    };
    
    for (int i = 0; i < len; i++) {
        if (list[i] == input) {
            correct_letters[i] = input;
            checked_successfully = 1;
        }
    };   

    int letter_is_not_correct = 0;
    for(int i = 0;i < 100;i++){
        if(input == checked_letters[i]){
            letter_is_not_correct = 1;
        }
    }

    if(checked_successfully == 0 && letter_is_not_correct == 0){
        stage++;
    }; 

    if(ok == sizeof(&checked_letters)/sizeof(checked_letters[0])){
        checked_letters[checked_num] = input;
        checked_num++;
    };

    check(len,list,correct_letters,checked_letters,checked_num,stage,rand_word);
}

int main() {
    time_t zeit = time(NULL);
    srand((unsigned int)zeit);

    const char *rand_word = WORDS[rand() % (sizeof(WORDS) / sizeof(WORDS[0]))];

    char rand_word_list[strlen(rand_word) + 1];

    for (int i = 0; i < strlen(rand_word); i++) {
        rand_word_list[i] = rand_word[i];
    }
    rand_word_list[strlen(rand_word)] = '\0';

    char correct_letters[strlen(rand_word)];
    for(int i = 0; i < strlen(rand_word);i++){
        correct_letters[i] = '_';
    };

    int checked_num = 0;
    char checked_letters[127] = {'_'};
    int stage = 0;
    check(strlen(rand_word), rand_word_list,correct_letters,checked_letters,checked_num,stage,rand_word);

    return 0;
}

