function acf = fast_rphacf(alpha,rho,T,nf)
% acf = fast_rphacf(alpha,rho,T,nf)


%
% fast_rphacf.m
%
% Original Author: Doug Greve
% CVS Revision Info:
%    $Author: nicks $
%    $Date: 2011/03/02 00:04:05 $
%    $Revision: 1.3 $
%
% Copyright © 2011 The General Hospital Corporation (Boston, MA) "MGH"
%
% Terms and conditions for use, reproduction, distribution and contribution
% are found in the 'FreeSurfer Software License Agreement' contained
% in the file 'LICENSE' found in the FreeSurfer distribution, and here:
%
% https://surfer.nmr.mgh.harvard.edu/fswiki/FreeSurferSoftwareLicense
%
% Reporting: freesurfer@nmr.mgh.harvard.edu
%

if(nargin < 1 | nargin > 4)
  fprintf('acf = fast_rphacf(alpha,rho,T,nf)\n');
  return;
end

tau = [0:nf-1]';
acf = alpha * (rho.^tau) .* cos(2*pi*tau/T);
acf(1) = 1;

return;


