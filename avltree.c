#include<stdio.h>
#include<stdlib.h>

struct node
{
  int info;
  struct node *rlink;
  struct node *llink;
  struct node *par;
};

typedef struct node*node;

node getnode();
void left(node root);
void right(node root);
void left_right(node root);
void right_left(node root);
void balance(node root);
node insert(int item,node root);
int height(node root);
void inorder(node root);



node getnode()
{
   node x;
   x=(node)malloc(sizeof(struct node));

   if(x==NULL)
   {
     printf("out of memory\n");
     exit(0);
   }
   return x;
}
void left_left(node temp)
{
   node top,a,b,c,l,r;
   a=temp;
   top=a->par;
   b=a->rlink;
   c=b->rlink;

   b->par=top;
   b->rlink=c;
   b->llink=a;
r=b->rlink;
l=b->llink;
printf("%d %d %d\n",b->info,l->info,r->info);



}
void right_right(node temp)
{
 node top,a,b,c,r,l;
   a=temp;
   top=a->par;
   b=a->llink;
   c=b->llink;

   b->par=top;
   b->llink=c;
   b->rlink=a;
r=b->rlink;
l=b->llink;
printf("%d %d %d\n",b->info,l->info,r->info);

  
}
void left_right(node root)
{
  node a,b,c,top,l,r;
  a=root;
  top=a->par;
  b=a->llink;
  c=b->rlink;

  c->par=top;
  c->rlink=a;
  c->llink=b;

r=c->rlink;
l=c->llink;
printf("%d %d %d\n",c->info,l->info,r->info);
 
  
}
void right_left(node root)
{
  node a,b,c,top,l,r;
  a=root;
  top=a->par;
  b=a->rlink;
  c=b->llink;

  c->par=top;
  c->llink=a;
  c->rlink=b;

r=c->rlink;
l=c->llink;
printf("%d %d %d\n",c->info,l->info,r->info);
 
  
}
void balance(node temp)
{
  int a,b,d;
  a=height(temp->llink);
  b=height(temp->rlink);

 //printf("%d %d\n",a,b);
 d=a-b;
 if(d==2||d==-2)
 {
  if(temp->llink==NULL&&temp->rlink->llink==NULL)
  {
    left_left(temp);
  }
  else if(temp->rlink==NULL&&temp->llink->rlink==NULL)
  {
    right_right(temp);
  }
  else if(temp->llink==NULL&&temp->rlink->rlink==NULL)
  {
    right_left(temp);
  }
  else if(temp->rlink==NULL&&temp->llink->llink==NULL)
  {
    left_right(temp);
  }
  }

}
node insert(int item,node root)
{
 node temp,prev,cur;
 temp=getnode();
 temp->llink=NULL;
 temp->rlink=NULL;
 temp->par=NULL; 
 temp->info=item;

 
 
 
if(root!=NULL)
{
 prev=NULL;
 cur=root;
 while(cur!=NULL)
 {
   prev=cur;
   if(item>cur->info)
       cur=cur->rlink;
   else
       cur=cur->llink;
 }
 if(item>=prev->info)
    {
     prev->rlink=temp;
     temp->par=prev;
    }
 else
    {
    prev->llink=temp;
    temp->par=prev;
    }


}

else if(root==NULL)
 {
   root=temp;
   //break;
 }

balance(temp);
return root;

}
int height(node root)
{
  int ldepth,rdepth;
 
  if(root==NULL)
     return 0;
  
  else
     ldepth=height(root->llink);
     rdepth=height(root->rlink);

     if(ldepth>rdepth)
         return (ldepth+1);
      
     else
         return (rdepth+1);

}
void inorder(node root)
{
   if(root==NULL) return;
   inorder(root->llink);
   printf("%d ",root->info); 
   inorder(root->rlink);
}

void main()
{
 int i,a[100],n;
 node root,r,l;
 printf("enter number of elements\n");
 scanf("%d\n",&n);
 for(i=0;i<n;i++)
{
   scanf("%d",&a[i]);
}
 for(i=0;i<n;i++)
  {
    if(i==0)
    {
       root=NULL;
    }
    root=insert(a[i],root);
  }
printf("successful insertion\n");
printf("inorder traversal of the tree\n");
inorder(root);
printf("\n");



}
