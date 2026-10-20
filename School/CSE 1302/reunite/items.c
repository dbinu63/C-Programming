#include "items.h"

//--------------------------------------------------

void itPrint(struct Item *it, int idx) {
    const char *statStr =
        it->status == CLM ? "CLM" :
        it->status == FND ? "FND" : "LST";

    printf("\n[%d]\n", idx);
    printf("ID: %d\n", it->id);
    printf("Cont: %s\n", it->contact);
    printf("Desc: %s\n", it->desc);
    printf("Stat: %s\n", statStr);
}

//--------------------------------------------------

int isNums(const char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '\n') continue;
        if (s[i] < '0' || s[i] > '9') return 0;
    }
    return 1;
}

//--------------------------------------------------

void searchItems(struct Item *hd) {
    int pass, att = 3, ok = 0;

    if (!hd) {
        printf("No items.\n");
        return;
    }

    char buf[100], key[100];
    int ch;

    struct Item *res[100];
    int cnt = 0;

    printf("\n--- SEARCH ---\n");

    struct Item *cur = hd;
    int idx = 1;

    printf("\n--- ACTIVE ---\n");

    while (cur) {
        if (cur->status != CLM) {
            itPrint(cur, idx);
            res[cnt++] = cur;
            idx++;
        }
        cur = cur->next;
    }

    if (!cnt) {
        printf("No active items.\n");
        return;
    }

    printf("\nENTER = all, or keyword: ");
    fgets(buf, 100, stdin);
    buf[strcspn(buf, "\n")] = 0;

    int filt = strlen(buf) > 0;
    strcpy(key, buf);

    struct Item *f[100];
    int fcnt = 0;

    if (filt) {
        for (int i = 0; i < cnt; i++) {
            struct Item *it = res[i];

            if (strstr(it->desc, key) ||
                strstr(it->contact, key)) {
                f[fcnt++] = it;
            }
        }
    } else {
        for (int i = 0; i < cnt; i++) {
            f[i] = res[i];
        }
        fcnt = cnt;
    }

    printf("\n--- RESULT ---\n");

    for (int i = 0; i < fcnt; i++) {
        itPrint(f[i], i + 1);
    }

    if (!fcnt) {
        printf("No match.\n");
        return;
    }

    printf("\nSelect (0 exit): ");
    fgets(buf, 10, stdin);
    sscanf(buf, "%d", &ch);

    if (ch <= 0 || ch > fcnt) return;

    struct Item *sel = f[ch - 1];

    while (att > 0) {
        printf("Pass (%d left): ", att);
        fgets(buf, 10, stdin);
        sscanf(buf, "%d", &pass);

        if (pass == sel->password) {
            ok = 1;
            break;
        }

        att--;
        printf("Wrong.\n");
    }

    if (!ok) {
        printf("Too many tries.\n");
        return;
    }

    printf("\n(1) CLAIM\n");
    printf("(2) EDIT\n");
    printf("(3) EXIT\n> ");

    fgets(buf, 10, stdin);
    int act;
    sscanf(buf, "%d", &act);

    switch (act) {

        case 1:
            sel->status = CLM;
            printf("This item has been claimed and removed from listings.\n");
            break;

        case 2: {
            char nc[15], nd[100], tmp[10];
            int ns;

            do {
                printf("New contact number (nums): ");
                fgets(nc, 15, stdin);
                nc[strcspn(nc, "\n")] = 0;

                if (!isNums(nc)) {
                    printf("Invalid input.\n");
                }

            } while (!isNums(nc));

            printf("New description: ");
            fgets(nd, 100, stdin);
            nd[strcspn(nd, "\n")] = 0;

            printf("New status (0 - CLAIM,1 - FOUND,2 - LOST): ");
            fgets(tmp, 10, stdin);
            sscanf(tmp, "%d", &ns);

            strcpy(sel->contact, nc);
            strcpy(sel->desc, nd);
            sel->status = (Status)ns;

            printf("Updated.\n");
            break;
        }

        default:
            printf("Cancel.\n");
            break;
    }
}

//--------------------------------------------------

struct Item *makeNew(int id, char contact[15], char desc[100], Status status) {
    struct Item *n = malloc(sizeof(struct Item));

    if (!n) {
        printf("Alloc fail.\n");
        return NULL;
    }

    n->id = id;
    strcpy(n->contact, contact);
    strcpy(n->desc, desc);
    n->status = status;

    n->password = rand() % 9000 + 1000;
    n->next = NULL;

    printf("New @ %p | PWD %d\n", (void*)n, n->password);

    return n;
}