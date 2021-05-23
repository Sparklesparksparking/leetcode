#define MAX_LEN 10000

bool IsMatch(char* a, char* b)
{
    int len = strlen(a);
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            cnt++;
        }
    }
    if (cnt != 1) {
        return false;
    }
    return true;
}

int ladderLength(char *beginWord, char *endWord, char **wordList, int wordListSize)
{
    if (beginWord == NULL || endWord == NULL || wordList == NULL || wordListSize == 0) {
        return 0;
    }

    for (int i = 0; i < wordListSize; i++) {
        if (strcmp(endWord, wordList[i]) == 0) {
            break;
        }
        if (i == wordListSize - 1) {
            return 0;
        }
    }

    int* mark = (int*)calloc(wordListSize, sizeof(int));
    char* queue[MAX_LEN] = {0};
    int head = 0;
    int tail = 0;
    queue[tail++] = beginWord;
    int step = 1;
    while (head != tail) {
        int layerLen = tail - head;
        for (int i = 0; i < layerLen; i++) {
            char* temp = queue[head++];
            if (strcmp(temp, endWord) == 0) {
                free(mark);
                return step;
            }
            for (int j = 0; j < wordListSize; j++) {
                if (mark[j] == 0 && IsMatch(temp, wordList[j])) {
                    mark[j] = 1;
                    queue[tail++] = wordList[j];
                }
            }
        }
        step++;
    }
    free(mark);
    return 0;
}