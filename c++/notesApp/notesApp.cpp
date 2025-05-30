#include <iostream>
#include <fstream>
#include "json.hpp"

class Note
{
private:
    std::string title;
    std::string content;

public:
    Note(const std::string &t, const std::string &c) : title(t), content(c) {}

    void create()
    {
        using namespace std;
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter content: ";
        getline(cin, content);
    };

    void view() const
    {
        std::ifstream infile("notes.json");
        if (!infile)
        {
            std::cout << "Error: Could not open notes.json.\n";
            return;
        }

        nlohmann::json j;
        infile >> j;
        infile.close();

        if (j.contains("notes"))
        {
            for (const auto &note : j["notes"])
            {
                std::cout << '\n'
                          << std::string(note["title"]) << '\n'
                          << std::string(note["content"]) << '\n';
            }
        }
        else
        {
            std::cout << "No notes found.\n";
        }
    }

    void save()
    {
        std::ifstream infile("notes.json");
        nlohmann::json j;

        if (infile)
        {
            infile >> j;
            infile.close();
        }

        if (!j.contains("notes"))
        {
            j["notes"] = nlohmann::json::array();
        }

        nlohmann::json newNote;
        newNote["title"] = title;
        newNote["content"] = content;

        j["notes"].push_back(newNote);

        std::ofstream file("notes.json");
        if (file)
        {
            file << j.dump(4);
            file.close();
            std::cout << "Note saved successfully to notes.json!\n";
        }
        else
        {
            std::cout << "Error saving the note.\n";
        }
    }

    void del() {
        std::cout << "Enter the title of the note to delete: ";
        std::string noteTitle;
        std::getline(std::cin, noteTitle);

        std::ifstream infile("notes.json");
        if (!infile) {
            std::cout << "Error: Could not open notes.json.\n";
            return;
        }

        nlohmann::json j;
        infile >> j;
        infile.close();

        if (!j.contains("notes") || !j["notes"].is_array()) {
            std::cout << "No notes found.\n";
            return;
        }

        auto& notesArray = j["notes"];
        size_t originalSize = notesArray.size();

        notesArray.erase(std::remove_if(notesArray.begin(), notesArray.end(),
            [&](const nlohmann::json& note) {
                return note["title"] == noteTitle;
            }), notesArray.end());

        if (notesArray.size() == originalSize) {
            std::cout << "Note not found.\n";
            return;
        }

        std::ofstream outfile("notes.json");
        if (outfile) {
            outfile << j.dump(4);
            outfile.close();
            std::cout << "Note deleted successfully!\n";
        } else {
            std::cout << "Error saving notes.json after deletion.\n";
        }

        if (noteTitle.empty()) {
            std::cout << "Invalid title. Deletion canceled.\n";
            return;
}
    }

};

int main()
{
    Note note("", "");
    int inp;

    while (true)
    {
        std::cout << "\n[1] Create Note";
        std::cout << "\n[2] View Note";
        std::cout << "\n[3] Save Note";
        std::cout << "\n[4] Delete Note";
        std::cout << "\n[5] Exit\n";
        std::cin >> inp;
        std::cin.ignore();

    if (inp == 5) {
        char confirm;
        std::cout << "Are you sure you want to exit? (y/n): ";
        std::cin >> confirm;
        if (confirm == 'y') {
            std::cout << "Goodbye...\n";
            break;
        } else {
            std::cout << "Exit canceled.\n";
        }
    }

    switch (inp) {
        case 1:
            note.create();
            break;
        case 2:
            note.view();
            break;
        case 3:
            note.save();
            break;
        case 4: {
            char confirm;
            std::cout << "Are you sure you want to delete a note? (y/n): ";
            std::cin >> confirm;
            std::cin.ignore();
            if (confirm == 'y') {
                note.del();
            } else {
                std::cout << "Deletion canceled.\n";
            }
            break;
            }
        default:
            std::cout << "Invalid choice, try again.\n";
        }
}
    
    return 0;
}