class Solution {
    int word[26] = { 0 };
    int func(char s)
    {
        return s - 'A';
    }
public:
    int characterReplacement(string s, int k) {
        int sSize = s.length();
        int answer = 0;
        int left = 0;
        int right = 0;
        word[func(s[right])]++;
        while (left < sSize && right < sSize)
        {
            int windowSize = (right - left) + 1;
            int maxWordCnt = *max_element(word, word + 26);
            if (windowSize - maxWordCnt > k)//k번내에 똑같은 문자로 못바꿀때
            {
                word[func(s[left])]--;//범위 줄여야 하니까 일단 범위 줄이기 전에 안쓰는 단어 횟수 --해준뒤 포인터 이동
                left++;
            }
            else
                //k번내 똑같은 문자로 바꿀 수 있을때
            {
                right++;
                if (right < sSize) word[func(s[right])]++;//범위를 넘어가면 안되니깨
                answer = max(answer, windowSize);
            }

        }
        return answer;
    }
};