#include <cstdio>
#include <cstdlib>

#include "sort.h"
#include "bs_tree.h"
#include "rb_tree.h"
#include "timer.h"
#include "random_generator.h"

int main(int argc, char *argv[])
{
	random_generator rg;
	rb_tree_i_info rb_info;
	bs_tree_i_info bs_info;
	timer t;
	int n, direction, tree;

	bs_info.reset();
	rb_info.reset();

	/*
 * check arguments
 */
	if (argc > 1)
	{
		n = atoi(argv[1]);
		n = (n < 1) ? 1 : n;
	}
	else
	{
		cout << argv[0] << " [n] [direction] [tree]" << endl;
		cout << "[n]              input size (nodes of the tree)" << endl;
		cout << "[direction]     -1: input is sorted descending" << endl;
		cout << "                 1: input is sorted ascending" << endl;
		cout << "                 0: input is random" << endl;
		cout << "[tree]           0: using bs tree" << endl;
		cout << "                 1: using rb tree" << endl;
		cout << endl;
		return 0;
	}

	if (argc > 2)
		direction = atoi(argv[2]);
	else
		direction = 0;

	if (argc > 3)
		tree = atoi(argv[3]);
	else
		tree = 0;

	/*
 * allocated and generate integer array
 */
	rb_tree rb;
	bs_tree bs;
	int *input_array;
	int bh;

	t.start();
	if (direction == 0)
		input_array = create_random(n);
	else
	{
		if (direction < 0)
			input_array = create_reverse_sorted(n);
		else
			input_array = create_sorted(n);
	}
	t.stop();

	cout << "Timer (generate): " << t << endl;

	// for (int i = 0; (i < n) && (i < 20); i++)
	// 	cout << input_array[i] << endl;
	// cout << endl;

	/*
 * run algorithms
 */
	if (tree == 0)
	{
		cout << "Running sort using BS trees: " << endl;
		t.start();
		for (int i = 0; i < n; i++)
			bs.insert(input_array[i], bs_info);
		n = bs.convert(input_array, n);
		t.stop();
	}
	else
	{
		cout << "Running sort using RB trees: " << endl;
		t.start();
		for (int i = 0; i < n; i++)
			rb.insert(input_array[i], rb_info);
		n = rb.convert(input_array, n);
		t.stop();
	}

	cout << "Timer (sort): " << t << endl;
	cout << "New size: " << n << endl;

	if (tree == 1)
	{
		t.start();
		bh = rb.check_black_height();
		if (bh > 0)
			cout << "Black height: " << bh << endl;
		else
			cout << "Black height check failed!" << endl;
		t.stop();

		cout << "Time (black height test): " << t << endl;
	}

	/*
 * check output
 */
	if (tree == 0)
	{
		//bs.output();

		cout << "Duplicates: " << bs_info.i_duplicate << endl;
	}
	else
	{
		//rb.output();

		cout << "Case 1: " << rb_info.i_case_1 << endl;
		cout << "Case 2: " << rb_info.i_case_2 << endl;
		cout << "Case 3: " << rb_info.i_case_3 << endl;
		cout << "Left Rotate: " << rb_info.i_left_rotate << endl;
		cout << "Right Rotate: " << rb_info.i_right_rotate << endl;
		cout << "Duplicates: " << rb_info.i_duplicate << endl;
	}

	if (check_sorted(input_array, 0, n - 1))
		cout << "The output is sorted!" << endl;
	else
		cout << "ERROR: The output is not sorted!" << endl;

	//rb.inorder_output();
	//rb.inorder_output();

	// for (int i = 0; (i < n) && (i < 20); i++)
	// 	cout << input_array[i] << endl;
	// cout << endl;

	/*
 * free allocated storage
 */
	delete[] input_array;

	return 0;
}
