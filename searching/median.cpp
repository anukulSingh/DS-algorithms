/* median of two sorted array in O(log(n1))
	make sure n1 < n2
	we need to do binary earch in smaller array ,and at any point make sure that
	half of elements are on left side, and half are on right side
	if i1 is start of right half in first array, then i2 is that of in second array
	where i2 = [(n1 + n2 + 1) / 2] - i1

	take the maximum el of two left halves
	take the minimu el of two right halves
	average them, and we will get the median

	terms:
	min1 - minimum element in right side of a1
	max1 - max element in left side of a1
	min2 - min element in right side of a1
	max2 - max element in left side of a2
 */


  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 > n2) { // make sure first array is lte second one
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
            
            int temp2 = n1;
            n1 = n2;
            n2 = temp2;
        }
        
        int start1 = 0, end1 = n1;
        while (start1 <= end1) {
            int i1 = start1 + (end1 - start1) / 2;
            int i2 = (n1 + n2 + 1) / 2 - i1;
            
            int min1 = (i1 == n1) ? INT_MAX : nums1[i1];
            int max1 = (i1 == 0) ? INT_MIN : nums1[i1 - 1];
            int min2 = (i2 == n2) ? INT_MAX : nums2[i2];
            int max2 = (i2 == 0) ? INT_MIN : nums2[i2 - 1];
            
            if (max1 <= min2 && max2 <= min1) {
                if ((n1 + n2) % 2 == 0) {
                    return ((double) max(max1, max2) + min (min1, min2)) / 2;
                } else {
                    return (double) (max(max1, max2));
                }
            } else if (max1 > min2) {
                end1 = i1 - 1;
            } else { // max2 > min1
                start1 = i1 + 1;
            }
        }
        return -1;
    }