pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
            bat 'Z:\HYEONGJUN KIM\Hyundai_Heavy_Industry\CI_script_for_AS\ci-as-build-scripts-master\scripts\Echo.bat Building...'
            bat 'Z:\HYEONGJUN KIM\Hyundai_Heavy_Industry\CI_script_for_AS\ci-as-build-scripts-master\scripts\Build.py'   
            }
        }
      stage('Install') {
         steps {
            bat 'Z:\HYEONGJUN KIM\Hyundai_Heavy_Industry\CI_script_for_AS\ci-as-build-scripts-master\scripts\Echo.bat Installing...'
            bat 'Z:\HYEONGJUN KIM\Hyundai_Heavy_Industry\CI_script_for_AS\ci-as-build-scripts-master\scripts\Install.bat'
         }
      }
      stage('Run') {
         steps {
            bat 'Z:\HYEONGJUN KIM\Hyundai_Heavy_Industry\CI_script_for_AS\ci-as-build-scripts-master\scripts\Echo.bat Running...'
            script{
                 withEnv(['JENKINS_NODE_COOKIE=dontkill']) {
                    bat 'Z:\HYEONGJUN KIM\Hyundai_Heavy_Industry\CI_script_for_AS\ci-as-build-scripts-master\scripts\Run.bat'
                 }
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