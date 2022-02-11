class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) 
{
	int m=grid.size(),n=grid[0].size();
	for(int i=0;i<m;i++) // flip the row if the leftmost is 1
		if(grid[i][0]==1)
			for(int j=0;j<n;j++) grid[i][j]=!grid[i][j];

	for(int j=1;j<n;j++) // flip the column if the uppermost is 1
		if(grid[0][j]==1)
			for(int i=0;i<m;i++) grid[i][j]=!grid[i][j];

	for(int i=0;i<m;i++) // check if any element is 1 in the grid
		for(int j=0;j<n;j++)
			if(grid[i][j]) return false;

	return true;
}
};