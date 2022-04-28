pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                dir("Z:\\HYEONGJUN KIM\\Hyundai_Heavy_Industry\\CI_script_for_AS\\ci-as-build-scripts-master\\scripts\\"){
                    bat 'Echo.bat Building...'
                    bat 'Build.py'
                }
            }
        }
      stage('Install') {
         steps {
                dir("Z:\\HYEONGJUN KIM\\Hyundai_Heavy_Industry\\CI_script_for_AS\\ci-as-build-scripts-master\\scripts\\"){
                    bat 'Echo.bat Installing...'
                    bat 'Install.bat'
                }
         }
      }
     
   
    }
   
   post {
      always {
         // This path takes WORKSPACE implicitly upfront, which for me is C:/Personal/Install/workspace/FirstPipeline/. 
         junit 'Reports/**/*.xml'
      }
   }
}