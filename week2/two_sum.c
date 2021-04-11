/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct hashTable{
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashTable* hashtable = NULL;

struct hashTable* find(int ikey)
{
    struct hashTable* tmp = NULL;
    HASH_FIND_INT(hashtable, &ikey, tmp);
    return tmp;
}
void insert(int ikey, int ival)
{
    struct hashTable* tmp = find(ikey);
    if (tmp == NULL){
        struct hashTable* it = malloc(sizeof(struct hashTable));
        it->key = ikey;
        it->val = ival;
        HASH_ADD_INT(hashtable, key, it);
    } else {
        tmp->val = ival;
    }  
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    if(nums == NULL || numsSize < 2) {
        return NULL;
    }
    *returnSize = 0;
    hashtable = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable *tmp = find(target - nums[i]);
        if (tmp != NULL) {
            int* ret = (int*)malloc(2 * sizeof(int));
            ret[0] = i;
            ret[1] = tmp->val;
            *returnSize = 2;
            return ret;
        } 
        insert(nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}
