#include <iostream>



template< int n , int d>
struct Ratio{
    static const int num = n;
    static const int den = d;
    typedef Ratio<n,d> type;
};
template<class R1, class R2>
struct Ratio_add{
    typedef Ratio<R1::num*R2::den+R1::den*R2::num,R1::den*R2::num> type;
};
template<int R1, int R2>
struct Ratio_subtract{
    typedef Ratio<R1::num*R2::den-R1::den*R2::num,R1::den*R2::den> type;
};



template <typename U, typename V, typename W>
struct Dim{
    using M = U; // kg
    using L = V; // m 
    using T = w; //s
    using type = Dim<M,L,T>;
};
template<typename D1, typename D2>
struct DimAdd{
    typedef Dim<
     typename Ratio_add<typename D1::M,typename D2::M>
    ,typename Ratio_add<typename D1::L,typename D2::L>
    ,typename Ratio_add<typename D1::T,typename D2::T>> type;
};
template<typename D1, typename D2>
struct DimSub{
    typedef Dim<
     typename Ratio_subtract<typename D1::M,typename D2::M>
    ,typename Ratio_subtract<typename D1::L,typename D2::L>
    ,typename Ratio_subtract<typename D1::T,typename D2::T>> type;
};


template <typename T, typename D>
struct quantity{
    T q;
    using dim_type = D;

    quantity operator+(quantity<T,D> quant) { return quantity<T,D> (q+quant.q)}
    quantity operator-(quantity<T,D> quant) { return quantity<T,D> (q-quant.q)}
};