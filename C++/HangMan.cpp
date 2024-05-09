#include <iostream>
#include <ctime>
#define start 0
#define goodguess  1
#define badguess  2
#define maxbadguess 6
using namespace std;
struct Hangman {
    string serectword;
    string guessedword;
    int badguesses;
    int hiddenletters;
    int status = start;
    void init(const string& serect) {
        serectword = serect;
        guessedword = string(serectword.length(),'_');
        badguesses = 0;
        hiddenletters = serectword.length();
    }
    void update(char input) {
        status = badguess;
        for (int i = 0;i < serectword.length();i++) {
            if (guessedword[i] == '_' && serectword[i] == input) {
                guessedword[i] = input;
                status = goodguess;
                hiddenletters--;
            }
        }
        if (status == badguess) badguesses++;
    }
    bool won() {
        return (hiddenletters <= 0);
    }
    bool lost() {
        return (badguesses > maxbadguess);
    }
    bool isOver(){
    return won() || lost();
}
};
    const string word_list[] = {"angle", "ant", "apple", "arch", "arm", "army",
        "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
        "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
        "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
        "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
        "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
        "cow", "cup", "curtain", "cushion",
        "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
        "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
        "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
        "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
        "hospital", "house", "island", "jewel",  "kettle", "key", "knee", "knife", "knot",
        "leaf", "leg", "library", "line", "lip", "lock",
        "map", "match", "monkey", "moon", "mouth", "muscle",
        "nail", "neck", "needle", "nerve", "net", "nose", "nut",
        "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
        "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
        "rail", "rat", "receipt", "ring", "rod", "roof", "root",
        "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
        "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
        "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
        "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
        "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
        "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm"};
    const int word_count = sizeof(word_list)/sizeof(string);
    const string& choose_word (){
        int randomIndex = rand() % word_count;
        return word_list[randomIndex];
    }
void render(Hangman& game) {
    if (game.status == badguess) cout <<"Bad Guess!";
    if (game.status == goodguess) cout <<"Good Guess!";
    cout <<"Bad gueses: " << game.badguesses << endl;
    cout <<"Guessed word: " << game.guessedword << endl;
    if (game.won()) cout <<"You won!";
    if (game.lost()) cout <<"You lost!";
}
char getInput() {
    string input;
    cout <<"Make a guess: ";
    cin >> input;
    return input[0];
}
int main(int argc, char** argv)
{
    srand(time(0));
    Hangman game;
    game.init(choose_word());
    render(game);
    do {
        char input = getInput();
        game.update(input);
        render(game);
    } while (!game.isOver());
}


