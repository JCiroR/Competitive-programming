const int MAXN = 100000;
int id[MAXN], size[MAXN];

void initialize()
{
    for(int i = 0;i < MAXN;++i) 
    {
        id[i] = i;
        size[i] = 1;
    }
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    if(p == q) return;
    if(size[p] < size[q]) 
    {
        id[p] = id[q];
        size[q] += size[p];
    } else {
        id[q] = id[p];
        size[p] += size[q];
    }
}

int setSize(int x) {
    x = root(x);
    return size[x];

}

int main(void) {
    return 0;
}