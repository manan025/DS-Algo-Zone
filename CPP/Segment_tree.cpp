#include<bits/stdc++.h>
using namespace std;

// maximum size for array
const int N = 1e5 + 5;
int a[N], tree[4*N + 1];

// function to build tree
void build(int node, int start, int end )
{
    // leaf node will have a single element
    if(start == end)
    {
        tree[node] = a[start];
        return;
    }

    int mid = (start + end)/2;

    // left child
    build(2*node, start, mid);

    // right child
    build(2*node + 1, mid +1, end);

    // Internal nodes will have sum of both its children
    tree[node] = tree[2*node] + tree[2*node + 1];

}


int query(int node, int start, int end, int l, int r)
{
    // range represented by a node is completely outside the given range
    // no overlap
    if(l > end || r < start) 
    return 0;

    // range represented by a node is completely inside the given range
    // complete overlap
    if(start >= l && end <= r) 
    return tree[node];
    
    // range represented by a node is partially inside and partially outside the given range

    int mid = (start + end) /2;

    int leftAns= query(2*node, start, mid, l, r);
    int rightAns = query(2*node +1, mid + 1, end, l, r);

    return leftAns + rightAns;
}

void update(int node, int start, int end, int index, int val)
{
    // leaf node
    if(start == end)
    {
        a[index] = val;
        tree[node]= val;
        return;
    }

    int mid = (start + end) /2;

    // If index is in the left child, recurse on the left child
    if(index <= mid )
    update(2*node, start, mid, index, val);
    
    // If index is in the right child, recurse on the right child
    else
    update(2*node + 1, mid +1, end, index, val);
    
    // Internal nodes will have sum of both its children
    tree[node] = tree[2*node] + tree[2*node + 1];
}

int main()
{
    int n, q;  // n-> size of array , q -> number of queries
    cin>>n>>q;
 
    for(int i=0; i<n; i++) 
    cin>>a[i];

    // Build tree from given array
    build(1, 0, n-1);

    while(q--)
    {
        int type, l, r;  // type 1 -> for range sum,  // type 2 -> for update 
        cin>>type>>l>>r;
        
        if(type == 1)
        {
            int ans = query(1, 0, n-1, l, r);
            // Print sum of elements from range l to r
            cout<<ans<<endl;
        }
        
        else // update a[l] to r
        update(1, 0, n-1, l, r);
    }
    return 0;
}