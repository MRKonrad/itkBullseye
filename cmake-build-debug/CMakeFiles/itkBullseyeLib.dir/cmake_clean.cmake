file(REMOVE_RECURSE
  "libitkBullseyeLib.pdb"
  "libitkBullseyeLib.dylib"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/itkBullseyeLib.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
