function [s,l, dlds, ddlds, theta,kappa] = getCurve(sf, dtheta, y_offset)
    s = 0:0.1:sf;

    c1 = @(dtheta_) tan(dtheta_);
    c2 = @(c1_, sf_, d_) -2*c1_/sf_ + 3*d_/sf_^2;
    c3 = @(c1_, c2_, sf_) -(c1_ + 2*c2_*sf_)/(3*sf_^2);
    f_l = @(c1_, c2_, c3_, s) (c1_.*s + c2_.*s.^2 + c3_.*s.^3);
    f_dlds = @(c1_, c2_, c3_, s) c1_ + 2*c2_.*s + 3*c3_.*s.^2;
    f_ddlds = @(c2_, c3_, s) 2*c2_ + 6*c3_.*s;


    c11 = c1(dtheta);
    c21 = c2(c11, sf, y_offset);
    c31 = c3(c11, c21, sf);
    
    l = f_l(c11, c21, c31, s);
    dlds = f_dlds(c11, c21, c31, s);
    theta = atan(dlds); % trajectory에선 불필요

    % kappa
    ddlds = f_ddlds(c21, c31, s);
    Q = sqrt(dlds.^2 + 1);
    kappa = (ddlds)./Q.^3;
end