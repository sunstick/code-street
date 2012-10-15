/* The Trie data structure */

class Trie {
private:
    bool mark;
    int count;
    string value;
    map<char, Trie *> children;

private:
    void insert(string str, int k);
    int search(string str, int k);

public:
    Trie(string v): value(v), count(0), mark(true) {}
    void insert(string str);
    int search(string str);
    void remove(string str);
};

void Trie::insert(string str, int k) {
    if (str != value) {
        if (!children.count(str[k]))
            children[str[k]] = new Trie(value + str[k]);
        children[str[k]] -> insert(str, k + 1);
    } else
        count++;
}

void Trie::insert(string str) {
    insert(str, 0);
}

int Trie::search(string str, int k) {
    if (value == str)
        return count;

    if (!children.count(str[k]) || !children[str[k]] -> mark)
        return 0;
    return children[str[k]] -> search(str, k + 1);
}

int Trie::search(string str) {
    return search(str, 0);
}

void Trie::remove(string str) {
}

void test() {
    Trie tr("");

    tr.insert("abc");
    tr.insert("abc");
    tr.insert("ant");
    tr.insert("bcd");
    tr.insert("to be or not to be");
    tr.insert("to be or not to be");
    tr.insert("to be or not to be");
    tr.insert("to be or not to be ");

    assert(tr.search("bcd") == 1);
    assert(tr.search("abc") == 2);
    assert(tr.search("012") == 0);
    assert(tr.search("ant") == 1);
    assert(tr.search("anc") == 0);
    assert(tr.search("abcdef") == 0);
    assert(tr.search("bc") == 0);
    assert(tr.search("to be or not to be") == 3);
    assert(tr.search("to be or not to be ") == 1);
    assert(tr.search(" to be or not to be") == 0);
}
