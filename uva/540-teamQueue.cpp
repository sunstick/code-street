#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

struct Node {
    int id;
    Node *next;
};

Node *head;
Node *tail;
map<int, int> group;
Node *maxId[1010];

Node *append(int id) {
    Node *nnode = (Node *)malloc(sizeof(Node));
    nnode->id = 0;
    nnode->next = NULL;
    tail->id = id;
    tail->next = nnode;
    nnode = tail;
    tail = tail->next;
    return nnode;
}

Node *insert(Node *pos, int id) {
    Node *nnode = (Node *)malloc(sizeof(Node));
    nnode->id = id;
    nnode->next = pos->next;
    pos->next = nnode;
    return nnode;
}

int main() {
    freopen("data.in", "r", stdin);
    int t, m, id;
    int k = 0;
    while (1) {
        cin >> t;
        if (t == 0)
            break;
        k++;
        cout << "Scenario #" << k << endl;

        group.clear();

        for (int i = 0; i < t; i++) {
            cin >> m;
            for (int j = 0; j < m; j++) {
                cin >> id;
                group[id] = i;
            }
        }

        head = (Node *)malloc(sizeof(Node));
        head->id = 0;
        head->next = 0;
        tail = head;

        string command;
        for (int i = 0; i < t; i++)
            maxId[i] = NULL;

        while (1) {
            cin >> command;
            if (command == "STOP") {
                cout << endl;
                break;
            }
            if (command == "ENQUEUE") {
                cin >> id;
                Node *pos = maxId[group[id]];
                if (pos == NULL) {
                    Node *nnode = append(id);
                    maxId[group[id]] = nnode;
                } else {
                    Node *nnode = insert(pos, id);
                    maxId[group[id]] = nnode;
                }
            } else if (command == "DEQUEUE") {
                int del = head->id;
                Node *pos = maxId[group[del]];
                cout << del << endl;
                head = head->next;
                if (del == pos->id)
                    maxId[group[del]] = NULL;
            }
        }
    }
    return 0;
}
