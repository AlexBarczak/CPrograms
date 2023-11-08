#ifndef HASHNODE
#define HASHNODE

#include<string>
using namespace std;

class HashNode {
    private:
        string key;
        string value;
    public:
        HashNode();
        HashNode(string k, string v);

        string getKey();

        string getValue();
        void setValue(string v);

        friend std::ostream& operator<<(std::ostream &output, const HashNode &hn);
};

#endif
