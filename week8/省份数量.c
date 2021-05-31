


int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    if (isConnected == NULL || isConnected <= 0 || isConnectedColSize[0] <= 0) {
        return 0;
    }
    int ret = 0;
    int* visited = (int*)calloc(isConnectedSize, sizeof(int));
    int left = 0; 
    int right = 0;
    int* queue = (int*)calloc(isConnectedSize * isConnectedSize, sizeof(int));

    for (int i = 0; i < isConnectedSize; i++) {
        if (visited[i] == false) {
            queue[right++] = i;
            while (left < right) {
                int j = queue[left++];
                visited[j] = true;
                for (int k = 0; k < isConnectedSize; k++) {
                    if (isConnected[j][k] == 1 && visited[k] == 0) {
                        queue[right++] = k;
                    }
                }
            }
            ret++;
        }
    }
    return ret;
}


//DFS
void Dfs(int** isConnected, int isConnectedSize, int* visited, int i)
{
    for (int j = 0; j < isConnectedSize; j++) {
        if(isConnected[i][j] == 1 && visited[j] == false) {
            visited[j] = true;
            Dfs(isConnected, isConnectedSize, visited, j);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    if (isConnected == NULL || isConnected <= 0 || isConnectedColSize[0] <= 0) {
        return 0;
    }
    int ret = 0;
    int* visited = (int*)calloc(isConnectedSize, sizeof(int));
    for (int i = 0; i < isConnectedSize; i++) {
        if (visited[i] ==  false) {
            visited[i] = true;
            Dfs(isConnected, isConnectedSize, visited, i);
            ret++;
        }
    }
    return ret;
}




//并查集
int Find(int* parent, int son) 
{
    if (parent[son] != son) {
        son = parent[son];
        parent[son] = Find(parent, son);
    }
    return parent[son];
}

void Join(int* parent, int son1, int son2)
{
    parent[Find(parent, son1)] = Find(parent, son2);
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    if (isConnected == NULL || isConnected <= 0 || isConnectedColSize[0] <= 0) {
        return 0;
    }

    int* parent = (int*)calloc(isConnectedSize, sizeof(int));
    for (int i = 0; i < isConnectedSize; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < isConnectedSize; i++) {
        for (int j = i + 1; j < isConnectedSize; j++) {
            if (isConnected[i][j] == 1) {
                Join(parent, i, j);
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < isConnectedSize; i++) {
        if (parent[i] == i) {
            ret++;
        }
    }
    return ret;
}
