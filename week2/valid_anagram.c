bool isAnagram(char * s, char * t){
    if (s == NULL && t == NULL) {
        return true;
    } else {
        if (s == NULL || t == NULL) {
            return false;
        }
    }
    int lens = strlen(s);
    int lent = strlen(t);
    if (lens != lent) {
        return false;
    }

    int* maps = (int*)calloc(26, sizeof(int));
    int* mapt = (int*)calloc(26, sizeof(int));

    for(int i = 0; i < lens; i++) {
        maps[s[i] - 'a']++;
        mapt[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (maps[i] != mapt[i]) {
            return false;
        }
    }

    return true;
}