#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_set>
#include<unordered_map>
#include<math.h>
using namespace std;
int arr[10000001];
int temp[10000001];
int n;
void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int leftIdx = start;//start~mid 값 보기위해 사용하는 index
    //왼쪽 덩어리의 시작점
    int rightIdx = mid;//mid ~ end 값 보기위해 사용하는 index
    //오른쪽 덩어리의 시작점. mid 부터 시작
    //정렬 하며 temp배열 채우기
    for (int i = start; i < end; i++)
    {
        if (rightIdx == end)//우측 배열의 인덱스가 이제 end에 다 닿으면 우측 배열이 다 끝났으니 이제 나머지 왼쪽 배열에 있는 값들 temp로 ㄱㄱ
        {
            temp[i] = arr[leftIdx];
            leftIdx++;
        }
        else if (leftIdx == mid)//왼쪽 배열을 이제 다 보냈으면
        {
            temp[i] = arr[rightIdx];
            rightIdx++;
        }
        else if (arr[leftIdx] <= arr[rightIdx])//왼쪽 배열의 값이 더 작으면 (오름차순이니) temp배열에 왼쪽 배열의 값을 저장하고 index ++
        {
            temp[i] = arr[leftIdx];
            leftIdx++;
        }
        else// 오른쪽 배열의 값이 더 작으면 오름차 순이니 temp배열의 오른쪽 배열의 값을 저장하고 다음 인덱스로 이동시킴
        {
            temp[i] = arr[rightIdx];
            rightIdx++;
        }

        
    }
    for (int i = start; i < end; i++)
    {
        arr[i] = temp[i];//temp에 임시 저장해둔 값을 a로 다시 옮김.
    }

}
void mergeSort(int start, int end)//배열을 1길이까지 나누는 과정 -> 재귀를 이용해서 리스트 길이 1까지 분할해버림.

{
    if (end == start + 1)// 리스트의 길이가 1인 경우에는 이미 정렬된 상태.
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(start, mid);// 왼쪽 절반 정렬
    mergeSort(mid, end);// 오른쪽 절반 정렬.
    merge(start, end);// 마지막에 두 덩어리를 합치면서 정렬

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(0, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << '\n';
    }
}