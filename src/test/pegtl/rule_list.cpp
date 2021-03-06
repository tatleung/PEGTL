// Copyright (c) 2014-2017 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#include "test.hpp"

namespace tao
{
   namespace TAOCPP_PEGTL_NAMESPACE
   {
      void unit_test()
      {
         verify_analyze< list< eof, eof > >( __LINE__, __FILE__, false, true );
         verify_analyze< list< eof, any > >( __LINE__, __FILE__, false, false );
         verify_analyze< list< any, eof > >( __LINE__, __FILE__, true, false );
         verify_analyze< list< any, any > >( __LINE__, __FILE__, true, false );

         verify_analyze< list< eof, eof, eof > >( __LINE__, __FILE__, false, true );
         verify_analyze< list< eof, eof, any > >( __LINE__, __FILE__, false, true );
         verify_analyze< list< eof, any, eof > >( __LINE__, __FILE__, false, true );
         verify_analyze< list< eof, any, any > >( __LINE__, __FILE__, false, false );
         verify_analyze< list< any, eof, eof > >( __LINE__, __FILE__, true, true );
         verify_analyze< list< any, eof, any > >( __LINE__, __FILE__, true, false );
         verify_analyze< list< any, any, eof > >( __LINE__, __FILE__, true, true );
         verify_analyze< list< any, any, any > >( __LINE__, __FILE__, true, false );

         verify_rule< list< one< 'a' >, one< ',' > > >( __LINE__, __FILE__, "", result_type::LOCAL_FAILURE, 0 );
         verify_rule< list< one< 'a' >, one< ',' > > >( __LINE__, __FILE__, "b", result_type::LOCAL_FAILURE, 1 );
         verify_rule< list< one< 'a' >, one< ',' > > >( __LINE__, __FILE__, ",", result_type::LOCAL_FAILURE, 1 );
         verify_rule< list< one< 'a' >, one< ',' > > >( __LINE__, __FILE__, ",a", result_type::LOCAL_FAILURE, 2 );
         verify_rule< list< one< 'a' >, one< ',' > > >( __LINE__, __FILE__, "a,", result_type::SUCCESS, 1 );
         verify_rule< list< one< 'a' >, one< ',' > > >( __LINE__, __FILE__, "a", result_type::SUCCESS, 0 );
         verify_rule< list< one< 'a' >, one< ',' > > >( __LINE__, __FILE__, "a,a", result_type::SUCCESS, 0 );
         verify_rule< list< one< 'a' >, one< ',' > > >( __LINE__, __FILE__, "a,b", result_type::SUCCESS, 2 );
         verify_rule< list< one< 'a' >, one< ',' > > >( __LINE__, __FILE__, "a,a,a", result_type::SUCCESS, 0 );
         verify_rule< list< one< 'a' >, one< ',' > > >( __LINE__, __FILE__, "a,a,a,a", result_type::SUCCESS, 0 );
         verify_rule< list< one< 'a' >, one< ',' > > >( __LINE__, __FILE__, "a,a,a,b", result_type::SUCCESS, 2 );
         verify_rule< list< one< 'a' >, one< ',' > > >( __LINE__, __FILE__, "a,a,a,,", result_type::SUCCESS, 2 );

         verify_rule< list< one< 'a' >, one< ',' > > >( __LINE__, __FILE__, "a ", result_type::SUCCESS, 1 );
         verify_rule< list< one< 'a' >, one< ',' > > >( __LINE__, __FILE__, " a", result_type::LOCAL_FAILURE, 2 );
         verify_rule< list< one< 'a' >, one< ',' > > >( __LINE__, __FILE__, "a ,a", result_type::SUCCESS, 3 );
         verify_rule< list< one< 'a' >, one< ',' > > >( __LINE__, __FILE__, "a, a", result_type::SUCCESS, 3 );

         verify_rule< list< one< 'a' >, one< ',' >, blank > >( __LINE__, __FILE__, "", result_type::LOCAL_FAILURE, 0 );
         verify_rule< list< one< 'a' >, one< ',' >, blank > >( __LINE__, __FILE__, " ", result_type::LOCAL_FAILURE, 1 );
         verify_rule< list< one< 'a' >, one< ',' >, blank > >( __LINE__, __FILE__, ",", result_type::LOCAL_FAILURE, 1 );
         verify_rule< list< one< 'a' >, one< ',' >, blank > >( __LINE__, __FILE__, "a ", result_type::SUCCESS, 1 );
         verify_rule< list< one< 'a' >, one< ',' >, blank > >( __LINE__, __FILE__, " a", result_type::LOCAL_FAILURE, 2 );
         verify_rule< list< one< 'a' >, one< ',' >, blank > >( __LINE__, __FILE__, "a ,a", result_type::SUCCESS, 0 );
         verify_rule< list< one< 'a' >, one< ',' >, blank > >( __LINE__, __FILE__, "a, a", result_type::SUCCESS, 0 );
         verify_rule< list< one< 'a' >, one< ',' >, blank > >( __LINE__, __FILE__, "a, a,", result_type::SUCCESS, 1 );
         verify_rule< list< one< 'a' >, one< ',' >, blank > >( __LINE__, __FILE__, "a, a ,", result_type::SUCCESS, 2 );
         verify_rule< list< one< 'a' >, one< ',' >, blank > >( __LINE__, __FILE__, " a , a ", result_type::LOCAL_FAILURE, 7 );
      }

   }  // namespace TAOCPP_PEGTL_NAMESPACE

}  // namespace tao

#include "main.hpp"
