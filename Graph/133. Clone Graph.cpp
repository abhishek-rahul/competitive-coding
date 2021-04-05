/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* old,Node *curr,vector<Node*> &visited)
    {
        Node* temp;
        Node* key;
        visited[curr->val]=curr;        
        for(int i=0;i<(old->neighbors).size();i++)
        {
            temp = (old->neighbors)[i];
            if(visited[temp->val]==NULL)
            {
                 key = new Node(temp->val);
                (curr->neighbors).push_back(key);
                dfs(temp,key,visited);
            }
            else
            {
                (curr->neighbors).push_back(visited[temp->val]);
            }
        }        
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        vector<Node*> visited(200,NULL);
        Node* temp;
        Node* key;
        Node *copy = new Node(node->val);
        visited[node->val] = copy;
        
        for(int i=0;i<(node->neighbors).size();i++)
        {
            temp = (node->neighbors)[i];
            if(visited[temp->val]==NULL)
            {
                 key = new Node(temp->val);
                (copy->neighbors).push_back(key);
                dfs(temp,key,visited);
            }
            else
            {
                (copy->neighbors).push_back(visited[temp->val]);
            }
        }
        return copy;
    }
};
