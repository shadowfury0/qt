// Unique.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/* ��Ӧ�̳�
 * STL �и� vector ȥ�ص����ַ���: https://xmuli.blog.csdn.net/article/details/126322011
 * STL �� std::set �����Զ���ṹ��Ķ��󣬶����ϸ�����ıȽϺ���: https://xmuli.blog.csdn.net/article/details/126354597
*/ 

struct MyData
{
    wstring name;
    wstring md5;

    // ��ʽһ�������� < ����
    //bool operator<(const MyData& d) const noexcept {
    //    return md5 < d.md5;
    //}
};

// ��ʽ�������Զ���ṹ�����ͣ��Զ���ȽϺ��� _Pr �����β��õķ�ʽ��
bool cmpSort(const MyData& d1, const MyData& d2) {
    // Simple example
    return d1.md5 < d2.md5;

    // Complex sample
    //if (d1.md5 != d2.md5)
    //    return d1.md5 < d2.md5;
    //else
    //    return d1.name < d2.name;
};

// ��ʽ�����֣�ͬ���������� Lambda ���ʽ��ĳЩ�����㷨�л�ʧЧ��
auto cmpSortLambda = [](const MyData& d1, const MyData& d2) {
    return d1.md5 < d2.md5;
};

// ��ʽ�������������ԡ����£�������д���Եģ��������˴���������ջ�
struct cmpSortObj
{
    bool operator()(const MyData& d1, const MyData& d2) const {
        return d1.md5 < d2.md5;
    }
};

// ************* std::unique ���Զ���ȽϺ��� *************
bool cmpUnique(const MyData& d1, const MyData& d2) {
    return d1.md5 == d2.md5;                             // ���ϸ������ȣ����ԴﵽĿ�꣬�����ڴ�й©
    //return d1.md5 == d2.md5 && d1.name == d2.name;     // �����﷨�ͱ��룬��������ʵ������
};

int main()
{
    vector<MyData> vec = { { L"a1.exe", L"B9204B6362A65C248950D5A41F341DCC"},
                           { L"a2.exe", L"B9204B6362A65C248950D5A41F341DCC"},
                           { L"b1.exe", L"C96D1AA5D314954417C28A645ED72665"},
                           { L"b2.exe", L"C96D1AA5D314954417C28A645ED72665"} };

    wcout.imbue(locale("", LC_CTYPE));
    wcout << L"----------����ǰ--------" << endl;
    for (const auto& it : vec)
        wcout << L"[it.name]" << it.name << L"[it.md5]" << it.md5 << endl;

    // ************* ��һ��vector, sort + unique *************
    //sort(vec.begin(), vec.end(), cmpSort);
    //auto ite = std::unique(vec.begin(), vec.end(), cmpUnique);
    //vec.erase(ite, vec.end());

    // ************* ������vector + set���ֶ���ֵ�� *************
    //set<MyData, cmpSortObj>  s;                           // "��������"���� set ���� --> OK
    set<MyData, decltype(cmpSort)*>  s(&cmpSort);           // "������ͨ���� + decltype"���� set ���� -->    OK:  ���롢���гɹ�������Ҳ�ɹ�
    //set<MyData, decltype(cmpSort)*>  s;                   //                                      --> Error:  ���롢���гɹ������Ի�ʧ��

    for (unsigned i = 0; i < vec.size(); ++i)
        s.insert(vec[i]);                                   // ����ʱ�����п���֤���洴�� std::set �Ľ��
    vec.assign(s.begin(), s.end());

    // ************* ������vector + set�����캯���� *************
    // Ч�ʲ��硺����������

    wcout << L"----------������--------" << endl;
    for (const auto& it : vec)
        wcout << L"[it.name]" << it.name << L"[it.md5]" << it.md5 << endl;

    return 0;
}