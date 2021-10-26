#ifndef __RB_TREE_H__
#define __RB_TREE_H__

enum rb_tree_color 
{
  RB_RED,
  RB_BLACK
};

struct rb_tree_node 
{
  int		key;
  int		color;
  rb_tree_node*	left;
  rb_tree_node*	right;
  rb_tree_node*	p;
};

struct rb_tree_i_info
{
  int i_case_1;
  int i_case_2;
  int i_case_3;
  int i_left_rotate;
  int i_right_rotate;
  int i_duplicate;

  void reset()
    { i_case_1 = i_case_2 = i_case_3 = i_duplicate = 
      i_left_rotate = i_right_rotate = 0; }
};

class rb_tree
{ 
  protected:
    rb_tree_node*	T_nil;
    rb_tree_node*	T_root;

  public:
    rb_tree();
    ~rb_tree();

    void insert(int, rb_tree_i_info&);
    int convert(int*, int);
    int check_black_height()
      { return check_black_height(T_root); }

    void inorder_output()
      { inorder_output(T_root, 1); }
    void output()
      { output(T_root, 1); }

  protected:
    void insert(rb_tree_node*, rb_tree_i_info&);
    void insert_fixup(rb_tree_node*&, rb_tree_i_info&);

    int check_black_height(rb_tree_node*);

    void remove_all(rb_tree_node*);

    void left_rotate(rb_tree_node*);
    void right_rotate(rb_tree_node*);

    void inorder_output(rb_tree_node*, int);
    void output(rb_tree_node*, int);
};


#endif
