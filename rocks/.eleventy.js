module.exports = function (eleventyConfig) {
  eleventyConfig.addPassthroughCopy("./src/css/");
  eleventyConfig.addWatchTarget("./src/css/");

  // - input/output customization if using -
  //
  //
  eleventyConfig.addCollection("specialCollection", function (collection) {
    return collection.getAll().filter((post) => post.data.customKey);
  });

//  return {
//    dir: {
//      input: "src",
//      output: "public",
//    },
//  };

  return {
    dir: {
// input: a must
      input: "src",
      output: "public",
    },
  };


//using the addCollection function to filter items in an existing collection. The new collection will be based on the existence of customKey within front matter. This key is returned off of the data object which is attached to all generated Eleventy content.

};
