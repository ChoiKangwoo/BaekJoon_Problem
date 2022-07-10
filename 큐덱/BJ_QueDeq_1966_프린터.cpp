#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Que {
public:
	vector <int> data;		//프린터 중요도가 저장되어 있는 벡터
	int size;		//프린터 용지 장 수
	vector<int>prioty;		//프린터 중요도가 오름차순으로 정렬되어 있는 벡터
	int m;

	Que(int size, int m) :size(size), m(m)		//Que 의 생성자, size와 M을 입력받아 저장시키고 data 와 prioty 벡터를 초기화 시킨다.
	{
		for (int i = 0; i < size; i++)
		{
			int n;
			cin >> n;
			data.push_back(n);
			prioty.push_back(n);
		}
		sort(prioty.begin(), prioty.end());	//중요도 오름차순 정렬

	}
	
};
int main()
{
	int N;
	cin >> N;		//테스트 갯수

	while (N--)
	{
		int size, m;
		cin >> size >> m;
		Que q(size, m);

		int i = 0;		//현재 인덱스
		int count = 0;		//프린터 된 횟수
		while (1)
		{
			if (q.data[i] == q.prioty.back())		//중요도가 제일 높다면
			{
				q.data[i] = 0;		//현재 인덱스의 배열 원소를 0으로 만들고(프린트 작업을 했다는 의미)
				q.prioty.pop_back();		//prioty 벡터의 마지막 원소를 삭제시킨다.(오름차순 정렬의 목적)
				count++;		//프린트를 했으니 count를 증가시킨다.
				if (i++ == m)		//만약 우리가 순서를 알아보고싶어 한 프린트 용지였다면 반복문을 나간다.
					break;
			}
			else      //q.data[i]<q.prioty.back()
			{
				q.data.push_back(q.data[i]);		//현재 인덱스의 원소를 제일 뒤에 추가시키고 0으로 초기화 시킨다.
				q.data[i] = 0;
				if (m == i++)		//우리가 순서를 알아보고 싶어한 프린트 용지라면 m 을 증가시켜 초기 M번째 용지와 순서를 맞춘다.
					m += size - count;
			}
		}
		cout << count << '\n';		//M번째 용지가 몇번째에 출력되었는지 출력한다.
	}
}