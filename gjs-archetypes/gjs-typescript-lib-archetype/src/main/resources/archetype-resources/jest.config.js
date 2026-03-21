#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $packagePath = ${package.replaceAll("\.","/")})
module.exports = {
  preset: 'ts-jest',
  testEnvironment: 'node',
  testMatch: ['<rootDir>/src/test/typescript/${packagePath}/**/*.test.ts']
};
