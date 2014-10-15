#ifndef RUNSEARCH_H
#define RUNSEARCH_H

void printStats(ofstream& outFile, SeqSearch seq, BinSearch bin, Hash hash, DHash dhash);
//***************************************************************************************
//Purpose: To print the statistical information about the different searches to an output
//         file
//Input: seq, bin, hash, dhash
//Pre: outFile is opened and ok; seq, bin, hash & dhash have value
//Output: outFile
//Post: The stats for each search have been printed to outFile
//Note: none
//***************************************************************************************

void printEndMsg(ofstream& outFile);
//******************************************************************
//Purpose: To print an end message to an output file
//Input: none
//Pre: outFile is opened and ok
//Output: outFile
//Post: An end message has been printed to outFile
//Note: none
//******************************************************************

void openCloseInFile(ifstream& inFile);
//******************************************************************
//Purpose: To close an input file and then open it again
//Input: inFile
//Pre: inFile is opened and ok
//Output: none
//Post: The input file was closed then opened again
//Note: Essentially just used to reset where inputting from the file
//      is
//******************************************************************


void printStats(ofstream& outFile, SeqSearch seq, BinSearch bin, Hash hash, DHash dhash)
//***************************************************************************************
//Purpose: To print the statistical information about the different searches to an output
//         file
//Input: seq, bin, hash, dhash
//Pre: outFile is opened and ok; seq, bin, hash & dhash have value
//Output: outFile
//Post: The stats for each search have been printed to outFile
//Note: none
//***************************************************************************************
{
 outFile << endl;
 outFile << "***< Summary Report >***" << endl;


 outFile << endl;
 outFile << "<<< ASL for Successful Search >>>" << endl;
 outFile << endl;
 outFile << left << setw(15) << "Sequential" 
 		      << setw(10) << "Binary" 
         << setw(20) << "Hashing Division" 
         << setw(20) << "Double Hashing" << endl;

 outFile << left << setw(15) << "----------" 
 		      << setw(10) << "------" 
         << setw(20) << "----------------" 
         << setw(20) << "--------------" << endl;

 outFile << left << setw(15) << seq.ASLSuccIs() 
 		      << setw(10) << bin.ASLSuccIs() 
         << setw(20) << hash.ASLSuccIs() 
         << setw(20) << dhash.ASLSuccIs() << endl;

 outFile << endl;
 outFile << "<<< ASL for Unsuccessful Search >>>" << endl;
 outFile << endl;
 outFile << left << setw(15) << "Sequential" 
         << setw(10) << "Binary" 
         << setw(20) << "Hashing Division" 
         << setw(20) << "Double Hashing" << endl;

 outFile << left << setw(15) << "----------" 
         << setw(10) << "------" 
         << setw(20) << "----------------" 
         << setw(20) << "--------------" << endl;

 outFile << left << setw(15) << seq.ASLUnSuccIs() 
         << setw(10) << bin.ASLUnSuccIs() 
         << setw(20) << hash.ASLUnSuccIs() 
         << setw(20) << dhash.ASLUnSuccIs() << endl;
}

void printEndMsg(ofstream& outFile)
//******************************************************************
//Purpose: To print an end message to an output file
//Input: none
//Pre: outFile is opened and ok
//Output: outFile
//Post: An end message has been printed to outFile
//Note: none
//******************************************************************
{
 outFile << endl;
 outFile << "*~ END ~*";
}

void openCloseInFile(ifstream& inFile)
//******************************************************************
//Purpose: To close an input file and then open it again
//Input: inFile
//Pre: inFile is opened and ok
//Output: none
//Post: The input file was closed then opened again
//Note: Essentially just used to reset where inputting from the file
//      is
//******************************************************************
{
 inFile.close();
 inFile.open("in.data");
}

#endif /* RUNSEARCH_H */