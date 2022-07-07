#include <iostream>

using namespace std;

typedef struct tree_element {//структура tree_element с определением типа чтобы не писать потом struct 
	int value; //значение
	struct tree_element* left; //указатель на левую дочернюю структуру
	struct tree_element* right; //указатель на правую дочернюю структуру
} tree_element;

tree_element* create_tree_element(int i);//функция создания нового элемента дерева с заданным значением, 
//возвращает указатель на объект структуры, принимает число  которое нужно вставить в дерево

//функция вставки элемента elem в дерево с корнем root 
void insert_into_tree(tree_element* root, tree_element* elem); //аргументы: в какое дерево вставлять, и что вставлять 

//функция печати дерева по возрастанию величин
void print_tree(tree_element* cur_elem);//принимает какой-то текущий элемент и печатает все что от него вниз - влево и вправо

//функция печати дерева в обратном порядке -по убыванию величин
void print_tree_des(tree_element* cur_elem);

//////////////////////////////////////////////////////////////////////////////////
int main()
{
	int a[7] = { -3, 1, -5, 42, 2, -6, 8 }; //массив интов
	tree_element* root = create_tree_element(0); //создаем корневой элемент с значанием 42 - пока у нас дерево из одного элемента
	for (int i = 0; i < 7; i++)
	{
		tree_element* el = create_tree_element(a[i]); //на каждой итерации создается новый элемент, он пока не состыкован с корнем
		insert_into_tree(root, el); //вставить элемент el после root
	}
	cout << "My tree: " << endl;
	print_tree(root); //печать начиная с корня по возрастанию величин

	cout << "Descending order: " << endl;
	print_tree_des(root);
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////

//выделяет память под элемент, инициализирует его поля и возвращает его
tree_element * create_tree_element(int i)
{
	tree_element* elem = new tree_element; //создаем новый элемент типа tree_element и присваиваем его переменной-указателю
	elem->value = i; //принимает значение
	elem->left = NULL;
	elem->right = NULL;
	return elem;
}

void insert_into_tree(tree_element * root, tree_element * elem) //функция должна рещить куда вставлять новый элемент - слева от root или справа
{
	if (elem->value < root->value) {//если значение элемента меньше чем значение в корне
	//идем в левое поддерево
		if (root->left == NULL) {//если левое поддерево пустое
			root->left = elem; //то вставляем сюда новый элемент - перекидываем указатель корня
		}
		else {//рекурсивно вставляем новый элемент, только базой теперь является не корень а левый элемент
			insert_into_tree(root->left, elem);
		}
	}
	else {//c правым поддеревом логика такая же
		if (root->right == NULL) {
			root->right = elem; //если нулевой правый то вставляем сюда - перенаправляем указатель корня
		}
		else insert_into_tree(root->right, elem);//если не пустой запускаем рекурсию по правому поддереву
	}
}

void print_tree(tree_element * cur_elem)
{
	if (cur_elem->left != NULL) {//если у текущего элемента поддерево слева не пустое
		print_tree(cur_elem->left); //то обработать рекурсивно левое поддерево
	}
	cout << "Value = " << cur_elem->value << endl;
	if (cur_elem->right != NULL) {// если у текущего правое поддерево не пустое
		print_tree(cur_elem->right); //то обработать рекурсией правое поддерево
	}
}

void print_tree_des(tree_element * cur_elem)
{
	if (cur_elem->right != NULL) {// если у текущего правое поддерево не пустое
		print_tree(cur_elem->right); //то обработать рекурсией правое поддерево
	}
	cout << "Value = " << cur_elem->value << endl;
	
	if (cur_elem->left != NULL) {//если у текущего элемента поддерево слева не пустое
		print_tree(cur_elem->left); //то обработать рекурсивно левое поддерево
	}
}
