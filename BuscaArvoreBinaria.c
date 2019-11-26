#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
  int num;
  struct tree* sad;
  struct tree* sae;
} Tree;

Tree* createTree()
{
  return NULL;
}

int treeIsEmpty(Tree* t)
{
  return t == NULL;

}

void showTree(Tree* t)
{
  if(!treeIsEmpty(t))
  {

    printf("%d ", t->num);
    showTree(t->sae);
    showTree(t->sad);
  }
}


void insertTree(Tree** t, int num)
{

  if(*t == NULL)
  {
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->sae = NULL;
    (*t)->sad = NULL;
    (*t)->num = num;
  } else {
    if(num < (*t)->num)
    {
      insertTree(&(*t)->sae, num);
    }
    if(num > (*t)->num)
    {
      insertTree(&(*t)->sad, num);
    }
  }
}


int isInTree(Tree* t, int num) {
  if(treeIsEmpty(t)) {
    return 0;
  }
  return t->num==num || isInTree(t->sae, num) || isInTree(t->sad, num);
}

int main(void)
{
Tree* t = createTree();

printf("Arvore: ");
insertTree(&t, 4);
insertTree(&t, 15);
insertTree(&t, 11);
insertTree(&t, 7);
insertTree(&t, 19);
insertTree(&t, 18);
insertTree(&t, 16);
insertTree(&t, 13);
insertTree(&t, 8);
insertTree(&t, 9);
insertTree(&t, 10);
insertTree(&t, 12);

showTree(t);

printf("\n");
printf("Escolha um numero a ser buscado na arvore: ");
int a;
scanf("%d", &a);
  if(isInTree(t, a)) {
    return 1;
  } else {
    return 0;
  }

  free(t);

}
