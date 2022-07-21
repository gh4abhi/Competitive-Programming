// Problem Link - https://www.codingninjas.com/codestudio/problems/841416?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int
#include<bits/stdc++.h>

class Node
{
    public:
    ll start;
    ll end;
    ll height;
    Node()
    {
        start = -1;
        end = -1;
        height = 0;
    }
};

int heightOfTheTree(vector<int>& inorder, vector<int>& level, int N)
{
  Node* root = new Node();
  root->height = 0;
  root->start = 0;
  root->end = N-1;
  queue<Node*> q;
  q.push(root);
  vector<ll> inPos(N+1);
  for(ll i=0;i<N;i++)
      inPos[inorder[i]] = i;
  ll height = 0;
  for(ll i=0;i<N;i++)
  {
      Node* cur = q.front();
      ll present = level[i];
      q.pop();
      if(inPos[present]>cur->start)
      {
          Node* newNode = new Node;
          newNode->height = cur->height+1;
          newNode->start = cur->start;
          newNode->end = inPos[present]-1;
          q.push(newNode);
          height = max(height,newNode->height);
      }
      if(inPos[present]<cur->end)
      {
          Node* newNode = new Node;
          newNode->height = cur->height+1;
          newNode->start = inPos[present]+1;
          newNode->end = cur->end;
          q.push(newNode);
          height = max(height,newNode->height);
      }
  }
  return height;
}
