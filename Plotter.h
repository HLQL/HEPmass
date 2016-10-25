/*
 * Plotter.h
 *
 *  Created on: 25.06.2012
 *      Author: csander
 */

#ifndef PLOTTER_H_
#define PLOTTER_H_

#include <vector>
#include <string>
#include <iostream>

#include <TH1F.h>
#include <TStyle.h>
#include <THStack.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TROOT.h>


class Plotter {
public:
	Plotter();
	virtual ~Plotter();
	void SetData(std::vector<TH1F*> v, std::string n, float l = 1.0){
		data.push_back(v);
		data_names.push_back(n);
		N_histos = v.size();
                luminosity = l; 
	}
	void ClearData(){
		data.clear();
		data_names.clear();
	}
	void AddBg(std::vector<TH1F*> v, std::string n, float x = 1.0){
                bg.push_back(v);
                bg_names.push_back(n);
                N_histos = v.size();
                bg_X.push_back(x);
	}
	void ClearBg(){
		bg.clear();
		bg_names.clear();
	}
	void AddSig(std::vector<TH1F*> v, std::string n, float x = 1.0){
		signal.push_back(v);
		signal_names.push_back(n);
		N_histos = v.size();
                signal_X.push_back(x);
	}
	void ClearSig(){
		signal.clear();
		signal_names.clear();
	}
	void Plot(std::string filename = "result.pdf");

private:
	std::vector < std::vector<TH1F*> > data;
	std::vector < std::vector<TH1F*> > bg;
	std::vector < std::vector<TH1F*> > signal;

	std::vector < std::string > data_names;
	std::vector < std::string > bg_names;
	std::vector < std::string > signal_names;
 
        std::vector < float > bg_X; 
        std::vector < float > signal_X;

	int N_histos;

        float luminosity; 

};

#endif /* PLOTTER_H_ */
