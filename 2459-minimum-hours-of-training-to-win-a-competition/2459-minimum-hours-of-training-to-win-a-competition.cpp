class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int totalEnergy{}, totalTime{};
        
        for(int i = 0; i < energy.size(); ++i)
        {
            totalEnergy += energy[i];
            
            if(initialExperience <= experience[i])
            {
                totalTime += experience[i] + 1 - initialExperience;
                initialExperience = experience[i] + 1;
            }
            initialExperience += experience[i];
        }
        
        int timeForEnergy = max(totalEnergy - initialEnergy + 1, 0);
        cout << timeForEnergy;
        return timeForEnergy + totalTime;
    }
};