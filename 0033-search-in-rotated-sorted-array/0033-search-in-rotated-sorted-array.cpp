class Solution {
public:
    int finding_pivot(vector<int> nums)
{
    int s = 0, e = nums.size() - 1, mid;

    while (s < e)
    {
        mid = s + (e - s) / 2;

        if (nums[mid] >= nums[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}

int binary_search(vector<int> nums, int s, int e, int target)
{
    int mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    int pivot = finding_pivot(nums);

    if (target >= nums[pivot] and target <= nums[nums.size() - 1])
    {
        return binary_search(nums, pivot, nums.size() - 1, target);
    }
    else
    {
        return binary_search(nums, 0, pivot - 1, target);
    }
}
};