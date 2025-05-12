#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    int edges;
    list<pair<int, int>> adjList;
    Node() { this->edges = 0; }
    Node(int data) { 
        this->data = data;
        this->edges = 0; }
};
class Graph{
public:
    vector<Node> graph;
    void addNode(int data){
        Node newNode{data};
        this->graph.push_back(newNode);
    }
    void addEdge(int src, int dest, int wt){
        this->graph[src].adjList.push_back({wt, dest});
        this->graph[src].edges++;
    }
    void show(){
        for(int i = 0; i<this->graph.size(); i++){
            cout << this->graph[i].data;
            for(auto it : this->graph[i].adjList){
                cout << "-( " << it.first << " )->" << it.second;
            }
            cout << endl;
        }
    }
    int Prims(){
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        set<int> visited;
        vector<int> weights(this->graph.size(), INT_MAX);
        int sum = 0;
        pq.push({0, 0, -1});
        while(!pq.empty()){
            vector<int> poped = pq.top();
            pq.pop();
            if(visited.find(poped[1]) != visited.end())
                continue;
            visited.insert(poped[1]);
            sum+=poped[0];
            int node = poped[1];
            for(auto it : this->graph[node].adjList){
                pq.push({it.first, it.second, node});
            }
        }
        return sum;
    }

};
int main(){
    int vertices, ch=1;
    cout << "Enter vertices : ";
    cin >> vertices;
    Graph graph{};
    for(int i = 0; i<vertices; i++){
        int node;
        cout << "Enter node value : ";
        cin >> node;
        graph.addNode(node);
    }
    cout << "Want to connect vertices : ";
    cin >> ch;
    while(ch){
        int src, dest, wt;
        cout << "Enter src : ";
        cin >> src;
        cout << "Enter dest : ";
        cin >> dest;
        cout << "Enter weight : ";
        cin >> wt;
        graph.addEdge(src, dest, wt);
        cout << "Want to connect vertices : ";
        cin >> ch;
    }
    graph.show();
    int mstSum = graph.Prims();
    cout << "Mst sum is : " << mstSum << endl;
}