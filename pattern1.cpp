#include <iostream>
#include <vector>
using namespace std;

class printer {
    public:
        virtual void print() {
            cout << "hello" << endl;
        };
};

class word : public printer {
    private:
        string wrd;
    public:
        word(string str) { wrd = str; };
        void print() {
            cout << wrd;
        };
};


class sentence : public printer {
    private:
        vector<printer*> words;
    public:
        sentence(vector<printer*> wrds) { words = wrds; };
        void print() {
            for (int i = 0; i < words.size(); i++) {
                words.at(i)->print();
                if (i < words.size() - 1) cout << " ";
            }
            cout << "." << endl;
        }
};



int main()  {
    
    printer* p1 = new word("hello");
    printer* p2 = new word("rachel");

    vector<printer*> words;

    words.push_back(p1);
    words.push_back(p2);

    printer* p3 = new sentence(words);

    p3->print();

    return 0;
}
