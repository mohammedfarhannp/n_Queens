class n_Queens:
    def __init__(self, Input):
        self.Input = Input
        self.Arrangements = 0
        self.State_List = [None for x in range(Input+1)]

    def Place(self, Index):
        i = 1
        while i < Index:
            if(self.State_List[i] == self.State_List[Index] or abs(self.State_List[i] - self.State_List[Index]) == abs(i - Index)):
                return False
            i += 1
        return True
    
    def Print_Board_Config(self):
        self.Arrangements += 1
        print(f"Arrangement #{self.Arrangements}")
        for i in range(1, self.Input+1):
            for j in range(1, self.Input+1):
                print("Q", end='') if(self.State_List[i] == j) else print(".", end='')
            print()
        print()
    
    def Config(self):
        Tracker = 1
        self.State_List[Tracker] = 0
        while (Tracker != 0):
            self.State_List[Tracker] += 1
            while (self.State_List[Tracker] <= self.Input and not self.Place(Tracker)):
                self.State_List[Tracker] += 1
                
            if(self.State_List[Tracker] <= self.Input):
                if(Tracker == self.Input):
                    self.Print_Board_Config()
                else:
                    Tracker += 1
                    self.State_List[Tracker] = 0
            else:
                Tracker -= 1

    def main(self):
        self.Config()