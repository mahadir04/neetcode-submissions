from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        for num in nums:
            if num not in freq:
                freq[num] = 0
            freq[num] += 1

        sorted_nums = sorted(freq, key=freq.get, reverse=True)
        return sorted_nums[:k]
