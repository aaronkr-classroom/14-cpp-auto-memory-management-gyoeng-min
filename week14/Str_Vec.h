#pragma once
//Str_Vec.h
#ifndef GUARD_Str
#define GUARD_Str

#include <algorithm>
#include <iterator>
#include <cstring>

#include "Vec.h"

class Str {
	//�Է¿�����
	friend std::istream& operator>>(std::istream&, Str&);

private:
	Vec<char> data;

public:
	typedef Vec<char>::size_type size_type;
	typedef char* iterator;//Q12
	typedef const char* const_iterator 

	//����ִ� Str��ü�� ����� �⺻ ������
	Str() { }//�ʱⰪ �߰�

	//c�� ���纻 n���� �ִ� Str��ü�� ����
	Str(size_type n, char c) : data(n, c) { }

	//null�� ������ char Ÿ���� �迭���� str ��ü�� ����
	Str(const char* cp) {
		std::copy(cp,
			cp + std::strlen(cp),
			std::back_inserter(data));
	}

	//�ݺ��� b�� e�� ����Ű�� �������� Str��ü�� ����
	template<class In>Str(In b, In e) {
		std::copy(b, e, std::back_inserter(data));
	}

	//�ε��� ������
	char& operator[](size_type i) { return data[i]; }
	const char& operator[](size_type i) const { return data[i]; }

	//����/ũ�� �Լ�
	size_type size() const { return data.size(); }

	//���� ������
	Str& operator+=(const Str& s) {
		std::copy(s.data.begin(), s.data.end(),
			std::back_inserter(data));
		return *this;

	}

	//Q12 begin(),end(),insert()
	iterator begin() { return data.begin(); }
	iterator end() { return data.end(); }
	iterator insert (iterator d, iterator b, iterator e){
		return data.insert(d, b, e);
	}

};

std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);

#endif
