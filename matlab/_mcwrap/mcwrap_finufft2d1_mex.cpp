/*
*
* This file was auto-generated by MCWRAP
* https://github.com/magland/mcwrap
*
* You should not edit this file.
* You might not even want to read it.
* 
*/ 

#include "mex.h"

#include "../finufft_mex.h"

//====================================================================
//====================================================================
        
int mcwrap_size(const mxArray *X,int j);

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{

      //mexPrintf("test A\n");
//   Check the number of inputs/outputs
      if (nlhs==0) nlhs=1;
      if (nrhs!=7)
         mexErrMsgTxt("Incorrect number of inputs"); 
      else if (nlhs>1)
         mexErrMsgTxt ("Too many outputs.");

      // mexPrintf("test A.2\n");
//    Setup the set inputs
        //M
        int input_M=(int)(mcwrap_size(prhs[3-1],1));

      //mexPrintf("test B\n");
//    Setup the inputs
        //N1
        double *p_input_N1=mxGetPr(prhs[1-1]);
        int input_N1=(int)p_input_N1[0];
        //N2
        double *p_input_N2=mxGetPr(prhs[2-1]);
        int input_N2=(int)p_input_N2[0];
        //isign
        double *p_input_isign=mxGetPr(prhs[5-1]);
        int input_isign=(int)p_input_isign[0];
        //tol
        double *p_input_tol=mxGetPr(prhs[6-1]);
        double input_tol=p_input_tol[0];
        //num_threads
        double *p_input_num_threads=mxGetPr(prhs[7-1]);
        int input_num_threads=(int)p_input_num_threads[0];
        //nonuniform_locations
        //Check that we have the correct dimensions!
        {
            int numdims=mxGetNumberOfDimensions(prhs[3-1]);
            if (numdims!=2) {
              mexErrMsgTxt("Incorrect number of dimensions in input: nonuniform_locations");
            }
            const mwSize *dims2=mxGetDimensions(prhs[3-1]);
            int dims[]={ input_M,2 };
            for (long ii=0; ii<numdims; ii++) {
              if (dims[ii]!=dims2[ii]) {
                mexErrMsgTxt("Incorrect size of input: nonuniform_locations");
              }
            }
        }
        double *input_nonuniform_locations=mxGetPr(prhs[3-1]);
        
        //nonuniform_data
        //Check that we have the correct dimensions!
        {
            int numdims=mxGetNumberOfDimensions(prhs[4-1]);
            if (numdims!=2) {
              mexErrMsgTxt("Incorrect number of dimensions in input: nonuniform_data");
            }
            const mwSize *dims2=mxGetDimensions(prhs[4-1]);
            int dims[]={ input_M,1 };
            for (long ii=0; ii<numdims; ii++) {
              if (dims[ii]!=dims2[ii]) {
                mexErrMsgTxt("Incorrect size of input: nonuniform_data");
              }
            }
        }
        double *input_nonuniform_data_re=mxGetPr(prhs[4-1]);
        double *input_nonuniform_data_im=mxGetPi(prhs[4-1]);
        double *input_nonuniform_data=(double *)malloc(sizeof(double)*((input_M)*(1)*2));
        for (long ii=0; ii<(input_M)*(1); ii++) {
            input_nonuniform_data[ii*2]=input_nonuniform_data_re[ii];
            if (input_nonuniform_data_im) {
                input_nonuniform_data[ii*2+1]=input_nonuniform_data_im[ii];
            }
            else {
                input_nonuniform_data[ii*2+1]=0;    
            }
        }
    
      //mexPrintf("test C\n");
//    Setup the outputs
        //uniform_data
        double *output_uniform_data_re;
        double *output_uniform_data_im;
        double *output_uniform_data;
        if (1<=nlhs) {
        if ((2<1)||(2>20)) {
          mexErrMsgTxt("Bad number of dimensions for my taste: 2"); 
        }
        {
            int dims2[]={ input_N1,input_N2 };
            for (long ii=0; ii<2; ii++) {
                if ((dims2[ii]<1)||(dims2[ii]>10000000000.0)) {
                  mexErrMsgTxt ("Bad array size for my taste: input_N1,input_N2"); 
                }
            }
        }
        
            mwSize dims[]={ input_N1,input_N2 };
            plhs[1-1]=mxCreateNumericArray(2,dims,mxDOUBLE_CLASS,mxCOMPLEX);
            output_uniform_data_re=mxGetPr(plhs[1-1]);
            output_uniform_data_im=mxGetPi(plhs[1-1]);
        }
        output_uniform_data=(double *)malloc(sizeof(double)*((input_N1)*(input_N2))*2);

    
      //mexPrintf("test D\n");
//    Run the subroutine
        finufft2d1_mex(
        input_M,
        input_N1,
        input_N2,
        output_uniform_data,
        input_nonuniform_locations,
        input_nonuniform_data,
        input_isign,
        input_tol,
        input_num_threads

        );
   
      //mexPrintf("test E\n");
//    Free the inputs
        //nonuniform_locations
        //nonuniform_data
        free(input_nonuniform_data);

      //mexPrintf("test F\n");
//    Set the outputs
        //uniform_data
        if (1<=nlhs) {
            for (long ii=0; ii<(input_N1)*(input_N2); ii++) {
                output_uniform_data_re[ii]=output_uniform_data[ii*2];
                output_uniform_data_im[ii]=output_uniform_data[ii*2+1];
            }
        }
        free(output_uniform_data);

      //mexPrintf("test G\n");

/**** We are done *******/
}

int mcwrap_size(const mxArray *X,int j) {
    mwSize numdims=mxGetNumberOfDimensions(X);
    if ((j<1)||(j>numdims)) return 1;
    const mwSize *dims2=mxGetDimensions(X);
    return dims2[j-1];
}

        //$pname$
//CC Scalar output not yet supported!