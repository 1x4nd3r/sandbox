#include <iostream>
#include <ctime>
#include <vector>

std::vector<std::string> determinator =
{
    "her", 
    "his", 
    "my", 
    "your", 
    "their", 
    "the", 
    "this", 
    "that", 
    "one single", 
    "THE"
};

std::vector<std::string> adjective =
{
    "cute", 
    "evil", 
    "sweet", 
    "fluffy", 
    "tough", 
    "menacing", 
    "secretive", 
    "gorgeous", 
    "rotten", 
    "smelly", 
    "mysterious", 
    "magnificent", 
    "shiny", 
    "majestic", 
    "peculiar", 
    "graceful", 
    "ancient", 
    "vibrant", 
    "chaotic", 
    "delicate"
};

std::vector<std::string> noun =
{
    "cat", 
    "dog", 
    "car", 
    "mum", 
    "God", 
    "hamster", 
    "woman", 
    "man", 
    "elder", 
    "youngster", 
    "wizard", 
    "knight", 
    "dragon", 
    "robot", 
    "alien", 
    "detective", 
    "pirate", 
    "ghost", 
    "scientist", 
    "artist"
};

std::vector<std::string> verb =
{
    "ran to", 
    "sneaked up on", 
    "sniffed", 
    "yelled at", 
    "barked at", 
    "ate", 
    "drank", 
    "fooled", 
    "worshipped", 
    "despised", 
    "danced with", 
    "chased", 
    "built", 
    "destroyed", 
    "painted", 
    "investigated", 
    "rescued", 
    "befriended", 
    "enchanted", 
    "licked"
};

std::vector<std::string> adverb =
{
    "weirdly", 
    "coldly", 
    "kindly", 
    "sincerely", 
    "happily", 
    "tiredly", 
    "questionably", 
    "forcefully", 
    "lazily", 
    "suddenly", 
    "gracefully", 
    "awkwardly", 
    "dramatically", 
    "mysteriously", 
    "fiercely", 
    "brilliantly", 
    "silently", 
    "innocently", 
    "reluctantly"
};

std::vector<std::string> punctuation =
{
    "!", 
    "?", 
    ".", 
    "..."
    "!!!", 
    "???",
    "~"
};

void generateSentence()
{
    std::string randomSentence = 
        determinator[rand() % determinator.size()] + ' ' +
        adjective[rand() % adjective.size()] + ' ' +
        noun[rand() % noun.size()] + ' ' +
        adverb[rand() % adverb.size()] + ' ' +
        verb[rand() % verb.size()] + ' ' +
        determinator[rand() % determinator.size()] + ' ' +
        adjective[rand() % adjective.size()] + ' ' +
        noun[rand() % noun.size()] +
        punctuation[rand() % punctuation.size()] + ' ';

    if (!randomSentence.empty()) {
        randomSentence[0] = toupper(randomSentence[0]);
    }

    std::cout << randomSentence;
}

int main() {
    srand(time(0));

    while (std::cin.get() == '\n') 
        generateSentence();

    return 0;
}