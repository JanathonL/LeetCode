82. Remove Duplicates from Sorted List II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        unordered_map<int,int> mymap;
        ListNode* cur = head;
        while(cur!=NULL){
            if(mymap.find(cur->val)==mymap.end()){
                mymap[cur->val] = 1;
            }
            else{
                mymap[cur->val] ++;
            }
            cur=cur->next;
        }
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        cur = prev->next;
        while(cur!=NULL){
            // cout<<cur->val<<endl;
            if(mymap[cur->val]>1){
                prev->next = cur->next;
                delete cur;
                
            }
            else{
                prev = prev->next;
            }
            cur = prev->next;
        }
        // cout<<dummy.next<<endl;
        return dummy.next;
    }
};


// refined
// beat 45%
// time: O(log(N))
// space: O(1)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0) return false;
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<=hi){  // careful about equal  [0,1,2]
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]>nums[hi]){
                if(target<nums[mid]&&target>=nums[lo]){
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else if(nums[mid]<nums[hi]){
                if(target>nums[mid]&&target<=nums[hi]){
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            } else {
                hi--;
            }
        }
        return false;
    }
};

