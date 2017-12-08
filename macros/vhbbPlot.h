#ifndef vhbbPlot_h
#define vhbbPlot_h

#include <TBranch.h>
#include <map>

namespace vhbbPlot {
  
  float theLumi=35900.;

  enum selectionType { 
    kWHLightFlavorCR,
    kWHHeavyFlavorCR,
    kWH2TopCR,
    kWHSR,
    kZnnHLightFlavorCR,
    kZnnHHeavyFlavorCR,
    kZnnH2TopCR,
    kZnnHMultijetCR,
    kZnnHSR,
    kZllHLightFlavorCR,
    kZllHHeavyFlavorCR,
    kZllH2TopCR,
    kZllHSR,
    nSelectionTypes
  };
  enum sampleType {
    kData       , // 0 
    kQCD        , // 1
    kVZ         , // 2
    kWW         , // 3
    kTT         , // 4
    kTop        , // 5
    kWjets      , // 6
    kZjets      , // 7
    kVH         , // 7
    nSampleTypes 
  };
  enum plotCategory {
    kPlotData , // 0  
    kPlotQCD  , // 1  
    kPlotVZbb , // 2  
    kPlotVVLF , // 3  
    kPlotTT   , // 4  
    kPlotTop  , // 5  
    kPlotWbb  , // 6  
    kPlotWb   , // 7  
    kPlotWLF  , // 8  
    kPlotZbb  , // 9  
    kPlotZb   , //10  
    kPlotZLF  , //11   
    kPlotVH   , //12   
    nPlotCategories
  };
  
  // This function loads the ith entry of the branch, only if it has not already been loaded
  int bLoad(TBranch *branch, Long64_t ientry) {
    if(!branch) return 0;
    int bytesRead=0;
    Long64_t readEntry = branch->GetReadEntry();
    if(readEntry != ientry) bytesRead = branch->GetEntry(ientry);
    return bytesRead;
  }

  std::map<plotCategory, int> plotColors={
    { kPlotData , kBlack      },
    { kPlotQCD  , kGray       },
    { kPlotVZbb , 842         },
    { kPlotVVLF , kAzure-9    },
    { kPlotTT   , kPink+8     },
    { kPlotTop  , kPink+7     },
    { kPlotWbb  , kViolet+2   },
    { kPlotWb   , kViolet+8   },
    { kPlotWLF  , kViolet+6   },
    { kPlotZbb  , kPink+2     },
    { kPlotZb   , kMagenta-10 },
    { kPlotZLF  , kPink+1     },
    { kPlotVH   , kRed+3      }
  };
  std::map<plotCategory, TString> plotNames={
    { kPlotData , "Data"     },
    { kPlotQCD  , "QCD"      },
    { kPlotVZbb , "VZ(bb)"   },
    { kPlotVVLF , "VV+LF"    },
    { kPlotTT   , "t#bar{t}" },
    { kPlotTop  , "Top"      },
    { kPlotWbb  , "W+bb"     },
    { kPlotWb   , "W+b"      },
    { kPlotWLF  , "W+udcsg"  },
    { kPlotZbb  , "Z+bb"     },
    { kPlotZb   , "Z+b"      },
    { kPlotZLF  , "Z+udcsg"  },
    { kPlotVH   , "WH(125)"  }
  };
  std::map<plotCategory, TString> plotBaseNames={
    { kPlotData , "Data" },
    { kPlotQCD  , "QCD"  },
    { kPlotVZbb , "VZbb" },
    { kPlotVVLF , "VVLF" },
    { kPlotTT   , "TT"   },
    { kPlotTop  , "Top"  },
    { kPlotWbb  , "Wbb"  },
    { kPlotWb   , "Wb"   },
    { kPlotWLF  , "WLF"  },
    { kPlotZbb  , "Zbb"  },
    { kPlotZb   , "Zb"   },
    { kPlotZLF  , "ZLF"  },
    { kPlotVH   , "VH"   }
  }; 
  std::map<selectionType, TString> selectionNames={ 
    { kWHLightFlavorCR    , "WHLightFlavorCR"    },
    { kWHHeavyFlavorCR    , "WHHeavyFlavorCR"    },
    { kWH2TopCR           , "WH2TopCR"           },
    { kWHSR               , "WHSR"               },
    { kZnnHLightFlavorCR  , "ZnnHLightFlavorCR"  },
    { kZnnHHeavyFlavorCR  , "ZnnHHeavyFlavorCR"  },
    { kZnnH2TopCR         , "ZnnH2TopCR"         },
    { kZnnHMultijetCR     , "ZnnHMultijetCR"     },
    { kZnnHSR             , "ZnnHSR"             },
    { kZllHLightFlavorCR  , "ZllHLightFlavorCR"  },
    { kZllHHeavyFlavorCR  , "ZllHHeavyFlavorCR"  },
    { kZllH2TopCR         , "ZllH2TopCR"         },
    { kZllHSR             , "ZllHSR"             }
  };
}

#endif