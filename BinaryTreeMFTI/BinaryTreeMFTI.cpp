#include <iostream>

using namespace std;

typedef struct tree_element {//��������� tree_element � ������������ ���� ����� �� ������ ����� struct 
	int value; //��������
	struct tree_element* left; //��������� �� ����� �������� ���������
	struct tree_element* right; //��������� �� ������ �������� ���������
} tree_element;

tree_element* create_tree_element(int i);//������� �������� ������ �������� ������ � �������� ���������, 
//���������� ��������� �� ������ ���������, ��������� �����  ������� ����� �������� � ������

//������� ������� �������� elem � ������ � ������ root 
void insert_into_tree(tree_element* root, tree_element* elem); //���������: � ����� ������ ���������, � ��� ��������� 

//������� ������ ������ �� ����������� �������
void print_tree(tree_element* cur_elem);//��������� �����-�� ������� ������� � �������� ��� ��� �� ���� ���� - ����� � ������

//������� ������ ������ � �������� ������� -�� �������� �������
void print_tree_des(tree_element* cur_elem);

//////////////////////////////////////////////////////////////////////////////////
int main()
{
	int a[7] = { -3, 1, -5, 42, 2, -6, 8 }; //������ �����
	tree_element* root = create_tree_element(0); //������� �������� ������� � ��������� 42 - ���� � ��� ������ �� ������ ��������
	for (int i = 0; i < 7; i++)
	{
		tree_element* el = create_tree_element(a[i]); //�� ������ �������� ��������� ����� �������, �� ���� �� ���������� � ������
		insert_into_tree(root, el); //�������� ������� el ����� root
	}
	cout << "My tree: " << endl;
	print_tree(root); //������ ������� � ����� �� ����������� �������

	cout << "Descending order: " << endl;
	print_tree_des(root);
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////

//�������� ������ ��� �������, �������������� ��� ���� � ���������� ���
tree_element * create_tree_element(int i)
{
	tree_element* elem = new tree_element; //������� ����� ������� ���� tree_element � ����������� ��� ����������-���������
	elem->value = i; //��������� ��������
	elem->left = NULL;
	elem->right = NULL;
	return elem;
}

void insert_into_tree(tree_element * root, tree_element * elem) //������� ������ ������ ���� ��������� ����� ������� - ����� �� root ��� ������
{
	if (elem->value < root->value) {//���� �������� �������� ������ ��� �������� � �����
	//���� � ����� ���������
		if (root->left == NULL) {//���� ����� ��������� ������
			root->left = elem; //�� ��������� ���� ����� ������� - ������������ ��������� �����
		}
		else {//���������� ��������� ����� �������, ������ ����� ������ �������� �� ������ � ����� �������
			insert_into_tree(root->left, elem);
		}
	}
	else {//c ������ ���������� ������ ����� ��
		if (root->right == NULL) {
			root->right = elem; //���� ������� ������ �� ��������� ���� - �������������� ��������� �����
		}
		else insert_into_tree(root->right, elem);//���� �� ������ ��������� �������� �� ������� ���������
	}
}

void print_tree(tree_element * cur_elem)
{
	if (cur_elem->left != NULL) {//���� � �������� �������� ��������� ����� �� ������
		print_tree(cur_elem->left); //�� ���������� ���������� ����� ���������
	}
	cout << "Value = " << cur_elem->value << endl;
	if (cur_elem->right != NULL) {// ���� � �������� ������ ��������� �� ������
		print_tree(cur_elem->right); //�� ���������� ��������� ������ ���������
	}
}

void print_tree_des(tree_element * cur_elem)
{
	if (cur_elem->right != NULL) {// ���� � �������� ������ ��������� �� ������
		print_tree(cur_elem->right); //�� ���������� ��������� ������ ���������
	}
	cout << "Value = " << cur_elem->value << endl;
	
	if (cur_elem->left != NULL) {//���� � �������� �������� ��������� ����� �� ������
		print_tree(cur_elem->left); //�� ���������� ���������� ����� ���������
	}
}
