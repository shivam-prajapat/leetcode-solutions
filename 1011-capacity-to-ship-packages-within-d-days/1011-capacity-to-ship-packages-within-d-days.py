class Solution(object):

    def finddays(self,mid, weights):
        sum = 0
        days = 1

        for i in range(len(weights)):
            if(sum+weights[i]>mid):
                days+=1
                sum = weights[i]
            else:
                sum+=weights[i]
        
        return days

    def shipWithinDays(self, weights, days):
        
        low = max(weights)
        high = sum(weights)

        while(low<=high):
            mid = low + (high - low )//2

            if(self.finddays(mid, weights)<=days):
                high = mid -1
            else:
                low = mid +1


        return low

            
        