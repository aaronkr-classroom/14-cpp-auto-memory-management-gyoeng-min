//Str_Vec.cpp
#include <iostream>
#include <iterator>
#include <cstring>

#include "Str_Vec.h"

//12.3.2/������216
std::istream& operator>>(std::istream& is, Str& s) {
	//������ �� ����
	s.data.clear();

	//������� ���� �б�
	char c;
	while (is.get(c) && isspace(c))
		;//�ƹ��͵� �� �ص���

	//��� ���ڰ� ������ ���� ������� �б�
	if (is) {
		do s.data.push_back(c);
		while (is.get(c) && !isspace(c))
			;//�ƹ��͵� �� �ص� ��

		//���� ������ �ٽ� ��Ʈ������ ������
		if (is)
			is.unget();
	}
	return is;
}

//���� 12.3.1/������ 216
std::ostream& operator<<(std::ostream& os, const Str& s) {
	for (Str::size_type i = 0; i != s.size(); ++i) {
		os << s[i];
	}
	return os;
}

//���� 12.3.3/������ 219
Str operator+(const Str& s, const Str& t) {
	Str r = s;
	r += t;
	return r;
}