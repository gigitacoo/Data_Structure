
//排序
const int N = 20;
typedef struct {
    int age;
} ItemType;
typedef struct {
    long key;
    struct ItemType *item;
} Record;
typedef Record List[N];